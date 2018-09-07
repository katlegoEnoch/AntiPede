//Filename: Bullet.cpp
//Author:   Stax The Engipreneur
//Date:     7 September 2018
//Details:  Definition of Bullet member functions

#include "Bullet.h"

Bullet::Bullet(const int& bulletX, const int& bulletY) : bulletX_{bulletX}, bulletY_{bulletY}
{
    //a bullet object is created at point where shot is fired
    //we need to know Gun's coordinates
}


void Bullet::moveBullet(const int& speed,const Direction& dir)
{
    cout << "Moving bullet upward" << endl;
}

