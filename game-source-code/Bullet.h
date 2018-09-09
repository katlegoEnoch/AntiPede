//Filename: Bullet.h
//Author:   Stax The Engipreneur
//Date:     04 September 2018
//Details:  Header file of Bullet object

#ifndef BULLET_H
#define BULLET_H

#include <tuple>
#include <iostream>
using namespace std;

#include "constants.h"

class Bullet{
    
public:
    //Bullet object is created whenever player shoots
    Bullet(const int&, const int&);
    tuple<int,int> getBulletCoords() const {return {bulletX_,bulletY_};};
    //fire bullet at specific speed in specific direction
    void moveBullet(const int&,const Direction&);
    //collision detection members
    void setBulletState(bool);
    bool getBulletState() const {return targetHit_;}
private:
    int bulletX_;
    int bulletY_;
    bool  targetHit_;
};

#endif

