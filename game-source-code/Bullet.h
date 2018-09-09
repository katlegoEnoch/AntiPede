//Filename: Bullet.h
//Author:   Stax The Engipreneur
//Date:     04 September 2018
//Details:  Header file of Bullet object

#ifndef BULLET_H
#define BULLET_H

#include <tuple>
#include <iostream>
#include <memory>
using namespace std;

#include "constants.h"

//a bullet now has a region of space that it covers
#include "Region.h"

class Bullet{
    
public:
    //Bullet object is created whenever player shoots
    Bullet(const int&, const int&);
    tuple<int,int> getBulletCoords() const {return {bulletX_,bulletY_};};
    //fire bullet at specific speed in specific direction
    void moveBullet(const int&,const Direction&);
    double getBulletSize() const {return bulletSize_;}
    void   setBulletSize(const double&); 
    //collision detection members
    void setBulletState(bool);
    bool getBulletState() const {return targetHit_;}
    //a bullet object will have an ability to calculate what its region is and share this information with other object
    shared_ptr<Region> computeBulletRegion();// calculated based on bullet's current x-position
    int getBulletHeight() const {return bulletY_;}
   
private:
    int  bulletX_;
    int  bulletY_;
    bool    targetHit_;
    double  bulletSize_;
    //a bullet object now maintains a record of region it covers
    shared_ptr<Region> bullet_region_;
};

//the region is not always there, it's only available upon demand

#endif

