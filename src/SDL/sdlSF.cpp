#include "sdlSF.h"
#include "Image.h"
#include <iostream>

using namespace std;

const int SIZE_SPRITE = 32;

///////////////////////////////// SDL CLASS ///////////////////////////////////////////////

SDLSimple::SDLSimple() : game(), soundwav(nullptr)
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // mise en place sdl fonts
    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // Mise en place SDL sound
    //cout << __FUNCTION__ << " , " << __FILE__ << " : " << __LINE__ << endl;
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        // SDL_Quit();exit(1);
        withSound = false;
    }
    else
        withSound = true;

    
    int dimx, dimy;
    dimx = game.getconstField().getDimX();
    dimy = game.getconstField().getDimY();
    dimx = dimx * SIZE_SPRITE;
    dimy = dimy * SIZE_SPRITE;


    // Creation de la fenetre si PLAY est choisi
    if(mainMenu.stateM == mainMenu.menuState::PLAY)
    {
        window = SDL_CreateWindow("LIF-Fighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (window == nullptr)
        {
            cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    // IMAGES
    im_iconRise.loadFromFile("data/Rise/Rise-icon.png", renderer);
    im_iconYukiko.loadFromFile("data/Yukiko/Yukiko-icon.png", renderer);
    background.loadFromFile("data/background.png", renderer);


    //Initialisation des animations de Rise
    tabRise[CharacterState::IDLE] = AnimationData("data/Rise/AnimationsRise.csv","idle");
    tabRise[CharacterState::WALK] = AnimationData("data/Rise/AnimationsRise.csv","walk");
    tabRise[CharacterState::WALKBACK] = AnimationData("data/Rise/AnimationsRise.csv","walkback");
    tabRise[CharacterState::CROUCH] = AnimationData("data/Rise/AnimationsRise.csv","crouch");
    tabRise[CharacterState::JUMP] = AnimationData("data/Rise/AnimationsRise.csv","jump");
    tabRise[CharacterState::PUNCH] = AnimationData("data/Rise/AnimationsRise.csv","punch");
    tabRise[CharacterState::KICK] = AnimationData("data/Rise/AnimationsRise.csv","kick");
    tabRise[CharacterState::LOSER] = AnimationData("data/Rise/AnimationsRise.csv","loser");
    tabRise[CharacterState::WINNER] = AnimationData("data/Rise/AnimationsRise.csv","winner");
    tabRise[CharacterState::START] = AnimationData("data/Rise/AnimationsRise.csv","start");
    tabRise[CharacterState::HIT] = AnimationData("data/Rise/AnimationsRise.csv","hit");
    // Ending fight
    im_EndingRise.loadFromFile("data/Rise/Ending_R.png", renderer);
    im_NameRise.loadFromFile("data/Rise/Name_R.png", renderer);


    //Initialisation des animations de Yukiko
    tabYukiko[CharacterState::IDLE] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "idle");
    tabYukiko[CharacterState::WALK] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "walk");
    tabYukiko[CharacterState::WALKBACK] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "walkback");
    tabYukiko[CharacterState::CROUCH] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "crouch");
    tabYukiko[CharacterState::PUNCH] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "punch");
    tabYukiko[CharacterState::KICK] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "kick");
    tabYukiko[CharacterState::HIT] = AnimationData("data/Yukiko/AnimationsYukiko.csv","hit");
    tabYukiko[CharacterState::LOSER] = AnimationData("data/Yukiko/AnimationsYukiko.csv","loser");
    tabYukiko[CharacterState::WINNER] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "winner");
    tabYukiko[CharacterState::START] = AnimationData("data/Yukiko/AnimationsYukiko.csv", "start");
 
    // Ending fight
    im_EndingYukiko.loadFromFile("data/Yukiko/Ending_Y.png", renderer);
    im_NameYukiko.loadFromFile("data/Yukiko/Name_Y.png", renderer);

    // FONTS
    font = TTF_OpenFont("data/fontMenu.ttf", 500);
    if (font == nullptr)
    {
        cout << "Failed to load fontMenu.ttf! SDL_TTF Error: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // SONS
    if (withSound)
    {
        soundmp3 = Mix_LoadMUS("data/main_theme.mp3");
        if (soundmp3 == nullptr)
            soundmp3 = Mix_LoadMUS("../data/main_theme.mp3"); // different chemin si le premier marche pas
        if (soundmp3 == nullptr)
        {
            cout << "Failed to load main_theme.wav! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }
    }

}

SDLSimple::~SDLSimple()
{

    Mix_FreeMusic(soundmp3);
    Mix_FreeChunk(soundwav);
    TTF_CloseFont(font);

    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLSimple::sdlAff()
{
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    //mainMenu.displayMenu();

    //Afficher les images de fond et les icones
    const Field &field = game.getconstField();

    background.draw(renderer, 0, 0, field.getDimX() * SIZE_SPRITE, field.getDimY() * SIZE_SPRITE);
    im_iconRise.draw(renderer, 0.5 * SIZE_SPRITE, 0.5 * SIZE_SPRITE, 200, 200);
    im_iconYukiko.draw(renderer, 43.5 * SIZE_SPRITE, 0.5 * SIZE_SPRITE, 200, 200);

    //Afficher le menu de départ
    font_color.r = 50;
    font_color.g = 50;
    font_color.b = 255;
    font_im.setSurface(TTF_RenderText_Solid(font, "Temps", font_color));
    font_im.loadCurrentSurface(renderer);
}

void SDLSimple::playMoveSound(const char *soundFile)  // jouer un son de mouvement (punch, kick, etc)
{
    if (soundwav != nullptr)
        Mix_FreeChunk(soundwav);

    soundwav = Mix_LoadWAV(soundFile);
    if (soundwav == nullptr)
    {
        SDL_Log("Failed to load sound: %s", Mix_GetError());
        return;
    }
    Mix_PlayChannel(-1, soundwav, 0);
}

void SDLSimple::hp_bar()
{

        SDL_Rect healthBar_player1 = { 200, 70, 490, 45 };
        SDL_Rect healthBar_player2 = { 910, 70, 490, 45 };

        SDL_Rect healthBarBackground_player1 = { 200, 75, 500, 50 };
        SDL_Rect healthBarBackground_player2 = { 900, 75, 500, 50 };


        // Determine the maximum and current health values
        int maxHealth = 20;
        int currentHealth_player1 = player.getHealth();
        int currentHealth_player2 = player2.getHealth();

        // Calculate the percentage of health remaining
        float healthPercentage_player1 = (float)currentHealth_player1 / maxHealth; 
        float healthPercentage_player2 = (float)currentHealth_player2 / maxHealth;

        // Calculate the current width of the health bar
        int currentWidth_player1 = (healthPercentage_player1 * healthBar_player1.w);
        int currentWidth_player2 = (healthPercentage_player2 * healthBar_player2.w);

        // Set the rectangle width to the calculated value
        healthBar_player1.w = currentWidth_player1;
        healthBar_player2.w = currentWidth_player2;

         // Render the health bar background rectangle
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200); // black color
        SDL_RenderFillRect(renderer, &healthBarBackground_player1);
        SDL_RenderFillRect(renderer, &healthBarBackground_player2);

        // Render the health bar rectangle
        SDL_SetRenderDrawColor(renderer, 200, 0, 0, 200); // red color
        SDL_RenderFillRect(renderer, &healthBar_player1);
        SDL_RenderFillRect(renderer, &healthBar_player2);
}

void SDLSimple::hitboxes(){
        Hitbox Player1Hitbox = player.gethitbox();
        Hitbox Player2Hitbox = player2.gethitbox();
        Player1Hitbox.Boxwidth_hitbox = AnimationWidth/NbFrames;
        Player1Hitbox.Boxheight_hitbox = AnimationHeight;
        Player2Hitbox.Boxwidth_hitbox = AnimationWidth2/NbFrames2;
        Player2Hitbox.Boxheight_hitbox = AnimationHeight2;

        SDL_Rect rectHitbox = {player.getPositionX()*SIZE_SPRITE,21*SIZE_SPRITE-AnimationHeight,Player1Hitbox.Boxwidth_hitbox,Player1Hitbox.Boxheight_hitbox};

        SDL_Rect rectHitbox2 = {player2.getPositionX()*SIZE_SPRITE,21*SIZE_SPRITE-AnimationHeight2,Player2Hitbox.Boxwidth_hitbox,Player2Hitbox.Boxheight_hitbox};

        if(SDL_HasIntersection(&rectHitbox,&rectHitbox2) && (player.PlayerState.state == CharacterState::States::PUNCH || player.PlayerState.state == CharacterState::States::KICK) && player2.PlayerState.state != CharacterState::States::HIT)
        {
            player2.setHealth(player2.getHealth()-1);
            player2.PlayerState.state = CharacterState::States::HIT;
        }else if(SDL_HasIntersection(&rectHitbox,&rectHitbox2) && (player2.PlayerState.state == CharacterState::States::PUNCH || player2.PlayerState.state == CharacterState::States::KICK) && player.PlayerState.state != CharacterState::States::HIT)
        {
            player.setHealth(player.getHealth()-1);
            player.PlayerState.state = CharacterState::States::HIT;
        }
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}

void SDLSimple::endgame()
{
    if(player.getHealth()== 0)
    {
        player.PlayerState.state = CharacterState::States::LOSER;
        player2.PlayerState.state = CharacterState::States::WINNER;
        im_EndingYukiko.draw(renderer,10*SIZE_SPRITE,5*SIZE_SPRITE,314,500);
        im_NameYukiko.draw(renderer,15*SIZE_SPRITE,5*SIZE_SPRITE,340,47);

    } else if(player2.getHealth() == 0)
    {

        player.PlayerState.state = CharacterState::States::WINNER;
        player2.PlayerState.state = CharacterState::States::LOSER;
        im_EndingRise.draw(renderer,10*SIZE_SPRITE,5*SIZE_SPRITE,314,500);
        im_NameRise.draw(renderer,15*SIZE_SPRITE,5*SIZE_SPRITE,340,47);

    }
}

void SDLSimple::sdlBoucle()
{
    SDL_Event events;
    bool quit = false;

    if (withSound)
    Mix_PlayMusic(soundmp3, -1);

    // tant que ce n'est pas la fin ...

    // Start the game

    while (!quit)
    {
        // tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT || mainMenu.stateM == mainMenu.menuState::QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN)
            {              // Si une touche est enfoncee
                switch(events.key.keysym.scancode)
                {
                    case SDL_SCANCODE_S:
                        game.keyboardActionP1('s'); //crouch player2     
                        break;
                    case SDL_SCANCODE_A:
                        game.keyboardActionP1('q'); //walk left player2
                        break;
                    case SDL_SCANCODE_D:
                        game.keyboardActionP1('d'); //walk right player2
                        break;
                    case SDL_SCANCODE_C:
                        game.keyboardActionP1('c'); //punch player1
                        playMoveSound("data/Rise/sounds/Rise_punch.wav");
                        break;
                    case SDL_SCANCODE_V:
                        game.keyboardActionP1('v'); //kick player1
                        playMoveSound("data/Rise/sounds/Rise_kick.wav");
                        break;
                    case SDL_SCANCODE_K:
                        game.keyboardActionP2('k'); //crouch player2
                        break;
                    case SDL_SCANCODE_J:
                        game.keyboardActionP2('j'); //walk left player2
                        break;
                    case SDL_SCANCODE_L:
                        game.keyboardActionP2('l'); //walk right player2
                        break;
                    case SDL_SCANCODE_B:
                        game.keyboardActionP2('b'); //punch player2
                        playMoveSound("data/Yukiko/sounds/Yukiko_punch.wav");
                        break;
                    case SDL_SCANCODE_N:
                        game.keyboardActionP2('n'); //kick player2
                        playMoveSound("data/Yukiko/sounds/Yukiko_kick.wav");
                        break;
                    case SDL_SCANCODE_ESCAPE:
                    case SDL_SCANCODE_G:
                        quit = true;
                        break;
                    default: break;
                }
            } else if (events.type == SDL_KEYUP)
            {
                if(player.PlayerState.state == CharacterState::States::WALK ||  player.PlayerState.state == CharacterState::States::WALKBACK 
                    || player.PlayerState.state == CharacterState::States::CROUCH || player.PlayerState.state == CharacterState::States::KICK || player.PlayerState.state == CharacterState::States::PUNCH)
                {
                    game.keyboardActionP1('\0');
                }
                if(player2.PlayerState.state == CharacterState::States::WALK ||  player2.PlayerState.state == CharacterState::States::WALKBACK 
                    || player2.PlayerState.state == CharacterState::States::CROUCH || player2.PlayerState.state == CharacterState::States::KICK || player2.PlayerState.state == CharacterState::States::PUNCH)
                {
                    game.keyboardActionP2('\0');
                }
            }
        }
    
        sdlAff();

    
        static int frameNumber = 0;
        static int frameNumber2 = 0;


        if(player.PlayerState.ResetFrames ==  true)
        {
            frameNumber = 0;
            player.PlayerState.ResetFrames = false;
        }

        if(player2.PlayerState.ResetFrames ==  true)
        {
            frameNumber2 = 0;
            player2.PlayerState.ResetFrames = false;
        }


        AnimationWidth = tabRise[player.PlayerState.state].AnimationWidth;
        AnimationHeight = tabRise[player.PlayerState.state].AnimationHeight;
        NbFrames = tabRise[player.PlayerState.state].NbFrames;

        AnimationWidth2 = tabYukiko[player2.PlayerState.state].AnimationWidth;
        AnimationHeight2 = tabYukiko[player2.PlayerState.state].AnimationHeight;
        NbFrames2 = tabYukiko[player2.PlayerState.state].NbFrames;

        Hitbox Player1Hitbox = player.gethitbox();
        Hitbox Player2Hitbox = player2.gethitbox();
        Player1Hitbox.Boxwidth_hitbox = AnimationWidth/NbFrames;
        Player2Hitbox.Boxwidth_hitbox = AnimationWidth2/NbFrames2;

        /*Mise en place de l'animation du Joueur 1*/
        Animation A(renderer,"data/Rise/spritesheets/spritesheetR_" + player.PlayerState.GetCurrentStateString() + ".png");
        A.Draw(player.getPositionX()*SIZE_SPRITE,21*SIZE_SPRITE-AnimationHeight,AnimationWidth/NbFrames,AnimationHeight);
        A.PlayFrame(0,0,AnimationWidth/NbFrames,AnimationHeight,frameNumber);
        A.Render(renderer);

        frameNumber++;
        if(frameNumber>NbFrames-1){
            if(player.PlayerState.state == CharacterState::States::START || player.PlayerState.state == CharacterState::States::HIT)
            {
                game.keyboardActionP1('\0');
            }
            frameNumber= 2;
        }
    

        /*Mise en place de l'animation du Joueur 2*/
        Animation A2(renderer,"data/Yukiko/spritesheets/spritesheetY_" + player2.PlayerState.GetCurrentStateString() + ".png");
        A2.Draw(player2.getPositionX()*SIZE_SPRITE,21*SIZE_SPRITE-AnimationHeight2,AnimationWidth2/NbFrames2,AnimationHeight2);
        A2.PlayFrame(0,0,AnimationWidth2/NbFrames2,AnimationHeight2,frameNumber2);
        A2.Render(renderer);

        frameNumber2++;
        if(frameNumber2>NbFrames2-1){
            if(player2.PlayerState.state == CharacterState::States::START || player2.PlayerState.state == CharacterState::States::HIT)
            {
                game.keyboardActionP2('\0');
            }
            frameNumber2= 2;
        } 

        hitboxes();
        hp_bar();
        endgame();



        SDL_RenderPresent(renderer); // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_Delay(130);
        }
    // }
}
