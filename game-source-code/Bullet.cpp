//Filename: Bullet.cpp
//Author:   Stax The Engipreneur
//Date:     7 September 2018
//Details:  Definition of Bullet member functions

#include "Bullet.h"

Bullet::Bullet(const int& bulletX, const int& bulletY) : bulletX_{bulletX}, bulletY_{bulletY}
{
    //a bullet object is created at point where shot is fired
    //we need to know Gun's coordinates
    //bullet starts out not active
    targetHit_ = false;
  
    bulletSize_ = 3.f;
    
}


void Bullet::moveBullet(const int& speed,const Direction& dir)
{
    switch(dir){
        case Direction::NORTH:
            bulletY_ -= speed;
            break;
        case Direction::EAST:
            bulletX_ += speed;
            break;
        case Direction::SOUTH:
            bulletY_ += speed;
            break;
        case Direction::WEST:
            bulletX_ -= speed;
            break;
        default:
            //do nothing for now
            break;
    }//end switch
}

void Bullet::setBulletState(bool state)
{
    targetHit_ = state;
    cout << "Bullet hit target" << endl;
}

//bullet's region is computed based on bullet's current position
shared_ptr<Region> Bullet::computeBulletRegion()
{
    //compute maximum and minimum values based on bullet's current position
    auto minValue = bulletX_ - bulletSize_;
    auto maxValue = bulletX_ + bulletSize_;
    //check that computed values are within bounds
    if(minValue < 0){
        //replace with zero
        minValue = 0;
    }
    if(maxValue > fieldWidth){
        //set to maximum
        maxValue = fieldWidth;
    }
    //construct Region object based on computed values and return to caller
    bullet_region_ = make_shared<Region>(minValue,maxValue);
   return bullet_region_;
}


void Bullet::setBulletSize(const double& size)
{
    bulletSize_ = size;
}
