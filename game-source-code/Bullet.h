//Filename: Bullet.h
//Author:   Stax The Engipreneur
//Date:     04 September 2018
//Details:  Header file of Bullet object

#ifndef BULLET_H
#define BULLET_H

#include <tuple>

class Bullet{
    
public:
    //create bullet at specific location on the grid
    Bullet(const int&, const int&);
    tuple<int,int> getBulletCoords() const;
    //fire bullet at specific speed in specific direction
    void fireBullet(const int&, const Direction&);
    
private:
    int bulletX_;
    int bulletY_;
};

#endif

