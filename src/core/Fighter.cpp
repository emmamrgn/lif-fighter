#include "Fighter.h"
#include "Hitbox.h"
#include "CharacterState.h"
#include <cassert>
#include <iostream>

Fighter::Fighter(){}

Fighter::Fighter(int x, int y, int hp, int height, int width)
{
    p_x = x;
    p_y = y;
    p_hp = hp;
    p_height= height;
    p_width = width;
}

Fighter::~Fighter()
{
}

void Fighter::setPosition(int x, int y)
{
    p_x = x;
    p_y = y;
}

void Fighter::setHealth(const int hp)
{
    p_hp = hp;
}

int Fighter::getPositionX() const
{
    return p_x;
}

int Fighter::getPositionY() const
{
    return p_y;
}

int Fighter::getHealth() const
{
    return p_hp;
}

void Fighter::start(const Field &f)
{
    PlayerState.Start();
}

void Fighter::left(const Field &f)
{
    PlayerState.Walk();
    if (f.isPositionValid(p_x - 1, p_y))
        p_x--;
    sethitbox(getPositionX(), getPositionY(),p_width,p_height);
}

void Fighter::right(const Field &f)
{
    PlayerState.Walkback();
    if (f.isPositionValid(p_x + 7, p_y))
        p_x++;
    sethitbox(getPositionX(), getPositionY(),p_width,p_height);

}

void Fighter::jump(const Field &f)
{
    PlayerState.Jump();
    
}

void Fighter::crouch(const Field &f)
{
    PlayerState.Crouch(); 
    sethitbox(getPositionX(), getPositionY(),p_width,p_height);
}

bool Fighter::isColliding(const Fighter &Player2)
{
    Hitbox Player1Hitbox = gethitbox();
    Hitbox Player2Hitbox = Player2.gethitbox();

    if (Player1Hitbox.getPositionX() + getPositionX() >= (Player2Hitbox.getPositionX() + Player2.getPositionX()) + Player2Hitbox.Boxwidth_hitbox &&
        (Player1Hitbox.getPositionX() + getPositionX()) + Player1Hitbox.Boxwidth_hitbox <= Player2Hitbox.getPositionX() + Player2.getPositionX() &&
        Player1Hitbox.getPositionY() + getPositionY() <= (Player2Hitbox.getPositionY() + Player2.getPositionX()) + Player2Hitbox.Boxheight_hitbox &&
        Player1Hitbox.Boxheight_hitbox + (Player1Hitbox.getPositionY() + getPositionY()) >= Player2Hitbox.getPositionY() + Player2.getPositionY())
    {
        return true;
    }
    else
    {
        return false;
    } 
}


void Fighter::kick(Fighter &P2)
{
    PlayerState.Kick();
    if (isColliding(P2))
    {

        P2.setHealth(P2.getHealth()-1);
        P2.PlayerState.Hit();
    } 
    sethitbox(getPositionX(), getPositionY(),p_width,p_height);
}

void Fighter::punch(Fighter &P2)
{
    PlayerState.Punch();
    if (isColliding(P2))
    {
        P2.setHealth(P2.getHealth()-1);
        P2.PlayerState.Hit();
    } 
    sethitbox(getPositionX(), getPositionY(),p_width,p_height);
}

void Fighter::sethitbox(int X, int Y, float width, float height)
{
    hitbox.setSizeH(width);
    hitbox.setSizeW(height);
    hitbox.setPositionX(X);
    hitbox.setPositionY(Y);
}

Hitbox Fighter::gethitbox() const
{
    return hitbox;
}
       
void Fighter::RegressionTest()
{
    Fighter f;
    assert(f.getPositionX() == 0);
    assert(f.getPositionY() == 0);
    assert(f.getHealth() == 100);
    //assert(!f.isKO());
    f.setHealth(0);
    //assert(f.isKO());
    f.setPosition(10, 10);
    assert(f.getPositionX() == 10);
    assert(f.getPositionY() == 10);
}