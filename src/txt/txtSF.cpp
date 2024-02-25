#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTXT.h"

#include "../core/Game.h"
#include "../core/Fighter.h"
#include "../core/Field.h"
#include "../core/Hitbox.h"

void txtAff (winTXT& win, const Game & game)
{
	const Field& field = game.getconstField();
	const Fighter& fighter1 = game.getconstFighter1();
	const Fighter& fighter2= game.getconstFighter2();

	win.clear();

	for(int x=0;x<field.getDimX();++x)
	{
		for(int y=0; y<field.getDimY();++y)
		{
			win.print(x,y,field.getXYasChar(x,y));
		}
	}

	win.print(fighter1.getPositionX(), fighter1.getPositionY(), 'A');

	win.print(fighter2.getPositionX(), fighter2.getPositionY(), 'I');

	win.draw();
}


void boucleTXT(Game& game)
// Creation d'une nouvelle fenetre en mode texte
// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
{
	winTXT win (game.getconstField().getDimX(), game.getconstField().getDimY());

	//creer un menu en mode TXT pour le choix du mode de jeu

	/*bool choix= true;
	int ch;
	ch=win.getCh();
	win.clear();
	win.print(0,0,"1. Duel");
	win.print(0,1,"2. Solo");
	win.print(0,2,"3. Options");
	win.print(0,3,"4. Quitter");
	win.draw();
	do{
		if(win.getCh()=='1')
		{
			game.Duel();
		}
		else if(win.getCh()=='2')
		{
			game.Solo();
		}
		else if(win.getCh()=='3')
		{
			game.Options();
		}
		else if(win.getCh()=='4')
		{
			game.QuitGame();
			choix = false;
		}
		else
		{
			//cout << "Choix incorrect" << endl;
		}
	}while(choix)*/

	bool ok= true;
	int c;

	//affichage de la vie des joueurs

	terminalClear();
	txtAff(win, game);
	do{
		c=win.getCh();
		if(c != '\0')
		{
			switch(c)
			{
			case 'z':
				game.keyboardActionP1('z');
				cout << "jump done" << endl;
				break;
			case 's':
				game.keyboardActionP1('s');
				cout << "crouch done" << endl;
				break;
			case 'd':
				game.keyboardActionP1('d');
				break;
			case 'q':
				game.keyboardActionP1('q');
				break;
			case '<':
				game.keyboardActionP1('<');
        		cout << "punch done" <<endl;
        		break;
    		case 'c':
        		game.keyboardActionP1('c');
        		cout<< "kick done" <<endl;
        		break;
			case 'i':
				game.keyboardActionP2('i');	
				cout << "jump done" << endl;			
				break;
			case 'k':
				game.keyboardActionP2('k');
				cout << "crouch done" << endl;
				break;
			case 'l':
				game.keyboardActionP2('l');
				break;
			case 'j':
				game.keyboardActionP2('j');
			case 'b':
        		game.keyboardActionP2('b');
        		cout << "punch done" <<endl;
        		break;
    		case '!':
        		game.keyboardActionP2('n');
        		cout<< "kick done" <<endl;
        		break;			
			case 'w' :
				ok =false;
				break;
			}
			
			terminalClear();
			txtAff(win, game);	
			cout <<" " << endl << endl;
			cout << "Health Player 1 : " << game.getconstFighter1().getHealth() << endl;
			cout << "Health Player 2 : " << game.getconstFighter2().getHealth() << endl;
			if(game.getconstFighter1().getHealth()<=0 || game.getconstFighter2().getHealth()<=0)
			{
				cout << "Round done : Press w to quit" << endl; 
			}
			cout << "pos Player 1 : " << game.getPlayer1().getPositionX() << "," << game.getPlayer1().getPositionY() << endl;
			cout << "pos Player 2 : " << game.getPlayer2().getPositionX() << "," << game.getPlayer2().getPositionY() << endl;
		}
	}while (ok);
}
