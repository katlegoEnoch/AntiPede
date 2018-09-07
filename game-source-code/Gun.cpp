//Filename: Gun.cpp
//Author:   Stax The Engipreneur
//Date:     07 September 2018
//Details:  Implementation of Gun member functions

#include "Gun.h"

Gun::Gun(const int& gun_x, const int& gun_y) : gun_x_{gun_x}, gun_y_{gun_y}
{}

tuple<int,int> Gun::getGunCoords() const
{
    return {gun_x_,gun_y_};
}

void Gun::moveGun(const int& deltaX, const int& deltaY)
{
    //change gun location by specified amount
    gun_x_ += deltaX;
    gun_y_ += deltaY;
}

void Gun::fireGun()
{
    
}
