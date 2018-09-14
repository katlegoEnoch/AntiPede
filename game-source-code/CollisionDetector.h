//Filename: CollisionDetector.h
//Author:   Stax The Engipreneur
//Details:  Class declaration of Collision Detector OBJECTDESCRIPTOR

#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

/*The basic idea is to provide objects with an ability to detect collisions. This will be achived by placing
 a collision detector object inside a basic object. Then we can use enum to provide a code for the various game
  objects that exist. When a collision is sensed a code will be given that specifies which object*/

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <tuple>
using std::tuple;
   
#include "Region.h"
#include "Segment.h"
#include "Bullet.h"



class CollisionDetector{
public:
    //now collision detector will also pass back a set of smaller centipedes to caller
    bool detectCollision(vector<Segment>&,vector<Bullet>&);
private:
    bool computeMatch(shared_ptr<Region>,shared_ptr<Region>);
    //function splits Centipede into smaller ones upon detecting a collision
    void splitCentipede(vector<Segment>&,const size_t&);

};

#endif


