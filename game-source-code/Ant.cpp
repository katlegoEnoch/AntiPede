//Filename: Ant.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  

//Can we get rid of the link between the bullet and the gun and focus on the link between the ant and the bullet
#include "Ant.h"

#include <iostream>
using namespace std;

shared_ptr<Gun>    Ant::gun_ = NULL;
Bullet Ant::bullet_{0,0};
Ant::Ant(const int& antX, const int& antY, const double& ant_size) : antX_{antX}, antY_{antY}, antSize_{ant_size}
{
     //if either boundary is beyond limits of the screen...
    if((antX_ < 0 || antX_ > fieldWidth) || (antY_ < 0 || antY_ > fieldHeight))
    {
        //throw exception
        throw AntCoordinatesOutOfFieldBounds{};
    }
    
    //ant size must be within 20% of field dimensions or else is considered too big for interesting game play
    //size of ant is limited
    if(antSize_ > 0.2*fieldWidth || antSize_ > 0.2*fieldHeight)
    {
        //throw exception if an attempt is made to construct is large ant
        throw AntSizeBeyondFieldBounds{};
    }
        
    //initialize the state of Ant's gun
    //call the gun constructor to place gun on top of ant
    gun_ = make_shared<Gun>(antX_+((antSize_-8)/2),antY_-10);
}

//when the ant moves its gun must follow..
void Ant::moveAnt(int deltaX, int deltaY)
{
   auto left_edge = fieldWidth - (10+antSize_);
   auto right_edge = 10;
    
    //if movement is to the right
    if(deltaX > 0){
        if(antX_ == left_edge){
        antX_ = antX_;
        }
        else{
        //change ant's x position by deltaX
        antX_+= deltaX;
        //gun's position must also change by deltaX
        gun_->moveGun(deltaX,0);
        }
    }//end if
    else{//if movement is to the left
        if(antX_ == right_edge){
            antX_ = antX_;
        }
        else{
            antX_ += deltaX;
            //gun must follow ant
           gun_->moveGun(deltaX,0);
        }
    }//end else
    //change ant's y position by deltaY
    antY_ += deltaY;
    //gun follows ant's movement
    gun_->moveGun(0,deltaY);
}

//Ant has a gun which has a bullet
Bullet Ant::releaseBullet()
{
    //compute gun's current location when shot is fired
    auto[gunX,gunY] = gun_->getGunCoords();
    //construct a bullet object at gun's current location
    auto bullet = Bullet(gunX,gunY);
    //assign bullet to private member
    setBullet(bullet);
    
    return bullet;
}

void Ant::setBullet(const Bullet& bullet)
{
    //set Ant's bullet to passed in pointer
    bullet_ = bullet;
}


