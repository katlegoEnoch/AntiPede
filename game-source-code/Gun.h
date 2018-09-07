//Filename: Gun.h
//Author:   Stax The Engipreneur
//Date:     04 September 2018
//Details:  Header file of Gun 

#ifndef GUN_H
#define GUN_H

#include <vector>
#include <tuple>
#include "Bullet.h"


class Gun{
public:
    //create a gun object at specific location
    Gun(const int&, const int&);
    void fireGun();
    int getGunSize() const;
    tuple<int,int> getGunCoords() const;
    //gun's movement follows that of the ant
    void followAnt();
    void moveGun(const int&, const int&);
    
private:
    //a gun has a set of bullets in its memory
    int gun_x_;
    int gun_y_;
    vector<Bullet> bullets_;
};

#endif   