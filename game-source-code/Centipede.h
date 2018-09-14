//Filename: Centipede.h
//Author:   Stax The Engipreneur
//Date:     03 September 2018
//Details:  Header file for Centipede object

#ifndef CENTIPEDE_H
#define CENTIPEDE_H


#include "Segment.h"
#include <memory>
using std::shared_ptr;

#include <vector>
using std::vector;

//A centipede is provided with collision sensing ability
#include "CollisionDetector.h"

/*The centipede can be responsible for controlling its segments'movement. The segments move themselves
 but the centipede controls the movement.*/
 
class CentipedeHasInvalidSegments {};

//The centipede is now responsible for crowning each of its segments
 
class Centipede{
    
public:
    //construct Centipede with certain number of Segments
    Centipede(const int&);

    //move Centipede at particular speed
    void moveCentipede(const int&);
    //add a segment to Centipede
    void addSegmentToCentipede(const shared_ptr<Segment> );
    size_t  numberOfSegments() const {return numberOfSegments_;}
    //returns i-th segment of Centipede
    Segment& getSegmentAt(const int& position) { return segments_.at(position);}
    //
    shared_ptr<Segment> getSegment(const int&);
    //
    vector<Segment>::iterator getBegin()  {return segments_.begin();}
    vector<Segment>::iterator getEnd()  {return segments_.end();}
    //now Centipede has a state - dead of alive
    bool isAlive() const {return centState_;};
    void setCentState(const bool& state) {centState_ = state;}
    //A centipede can now be commanded to check for collisions with any number of bullets
    void checkBulletCollisions(vector<Bullet>&);

    
private:
    //a centipede has a number of segments that it maintains in its memory
    vector<Segment> segments_;
    int numberOfSegments_;
    //now Centipede has state
    bool centState_;
    //we decided to provide each centipede collision sensing ability
    shared_ptr<CollisionDetector> detector_;

};//end Centipede class definition

#endif