#include "Hitbox.h"
#include <iostream>
#include <cassert>

#include <iostream>

using namespace std;

Hitbox::Hitbox() 
{
}

Hitbox::~Hitbox() {}

void Hitbox::hitbox(int x, int y)
{
    Hitbox_x = x;
    Hitbox_y = y;
}

void Hitbox::setPositionX(int x)
{
    Hitbox_x = x;
}

void Hitbox::setPositionY(int y)
{
    Hitbox_y = y;
}

int Hitbox::getPosition()
{
    return Hitbox_x;
    return Hitbox_y;
}

int Hitbox::getPositionX()
{
    return Hitbox_x;
}

int Hitbox::getPositionY()
{
    return Hitbox_y;
}

void Hitbox::setSize(int Boxwidth, int Boxheight)
{
    Boxwidth_hitbox = Boxwidth;
    Boxheight_hitbox = Boxheight;
}

int Hitbox::getSizeW()
{
    return Boxwidth_hitbox;
}


int Hitbox::getSizeH()
{
    return Boxheight_hitbox;
}


void Hitbox::setSizeW(int Boxwidth)
{
    Boxwidth_hitbox = Boxwidth;
}

void Hitbox::setSizeH(int Boxheight)
{
    Boxheight_hitbox = Boxheight;
}

void Hitbox::RegresstionTest()
{
    Hitbox hitbox1;
    Hitbox hitbox2;
    //faire tests de regression avec assert  
}
