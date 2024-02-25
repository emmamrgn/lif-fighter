#include "Game.h"
#include <iostream>
#include "Fighter.h"
#include "Hitbox.h"
#include <unistd.h>

Game::Game() : F(), Player1(), Player2()
{

    Player1.setPosition(13,9);
    Player2.setPosition(30, 9);

    Player1.setHealth(20);
    Player2.setHealth(20);

    Player1.sethitbox(0, 0, 0, 0);
    Player2.sethitbox(0, 0, 0, 0);

}

Game::~Game(){}

Fighter &Game::getPlayer1()
{
    return Player1;
}

Fighter &Game::getPlayer2()
{
    return Player2;
}

const Fighter &Game::getconstFighter1() const
{
    return Player1;
}

const Fighter &Game::getconstFighter2() const
{
    return Player2;
}

const Field &Game::getconstField() const
{
    return F;
}

bool Game::keyboardActionP1(const char keybind)
{
    //switch touches clavier pour joueur 1
    switch (keybind)
    {
    case 'z':
        Player1.jump(F);
        break;
    case 's':
        Player1.crouch(F);
        break;
    case 'd':
        Player1.right(F);
        break;
    case 'q':
        Player1.left(F);
        break;
    case 'v':
        Player1.kick(Player2);
        break;
    case 'c':
        Player1.punch(Player2);
        break;
    case '\0':
        Player1.PlayerState.Idle();
        break;
    }
    return false;
}

bool Game::keyboardActionP2(const char keybind)
{
    //switch touches clavier pour joueur 2
    switch (keybind)
    {
    case 'i':
        Player2.jump(F);
        break;
    case 'k':
        Player2.crouch(F);
        break;
    case 'l':
        Player2.right(F);
        break;
    case 'j':
        Player2.left(F);
        break;
    case 'n':
        Player2.kick(Player1);
        break;
    case 'b':
        Player2.punch(Player1);
        break;
    case '\0':
        Player2.PlayerState.Idle();
        break;
    }
    return false;
}

void Game::regressionTest()
{
    Game g;
    assert(g.getPlayer1().getPositionX()==13);
    assert(g.getPlayer1().getPositionY()==7);
    assert(g.getPlayer1().getHealth()==100);

    assert(g.getPlayer1().gethitbox().getPositionX()==1);
    assert(g.getPlayer1().gethitbox().getPositionY()==1);
    assert(g.getPlayer1().gethitbox().getSizeH()==1);
    assert(g.getPlayer1().gethitbox().getSizeW()==1);

    const char keybind = 'a';
    assert(g.keyboardActionP1(keybind)==true);
}

