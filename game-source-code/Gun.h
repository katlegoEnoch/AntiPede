//Filename: Gun.h
//Author:   Stax The Engipreneur
//Date:     04 September 2018
//Details:  Header file of Gun 

#ifndef GUN_H
#define GUN_H

#include "Bullet.h"

class Gun{
public:
    Gun(const int&, const int&);
    void fireGun();
private:
    //a gun has a set of bullets in its memory
    vector<Bullet> bullets_;
};

#endif   