//File_name: Segment.h
//Author:    Stax The Engipreneur
//Date:      31 August 2018
//Details:   

#ifndef   SEGMENT_H
#define   SEGMENT_H

/*A centipede is made up of segments*/
#include <tuple>
#include <iostream>
using namespace std;

#include "constants.h"
#include "Region.h"

//empty classes representing an exceptions
class SegmentHasInvalidFieldCoordinates {};
class SegmentRadiusBeyondFieldBounds {};

class Segment{
public:
    //construct Segment object with specific location on field and size
    Segment(const int&, const int&, const double&, const Direction&);
    //clients of Segment can...
    tuple<int,int> getSegmentCoords() const {return {segmentX_,segmentY_};}
    //move Segment by specified amount
    void moveSegment(const int&, const int&);
    //move member that takes in number of steps and direction
    void move(const int&, const Direction&);
    //set the segment's direction of travel
    void setDirection(Direction dir)  {segmentDir_ = dir;}
    //get the segment's current direction of travel
    Direction getDirection() const {return segmentDir_;}
    //get segment size
    int segmentSize() const {return segmentSize_;}
    //ensure that segment never moves beyond edges
    bool onRightEdge() const;
    bool onLeftEdge() const;
    //collision sensing
    void setSegmentState(bool);
    bool segmentIsAlive() const {return segmentAlive_;}
    //other game objects can query a segment what region it covers
    shared_ptr<Region> computeSegmentRegion();

private:

    //has a coordinate on the field
    int segmentX_;
    int segmentY_;
    //has a size i.e radius
    double segmentSize_;
    //has a direction of travel
    Direction segmentDir_;
    //segment has a state - dead or alive
    bool segmentAlive_;
    //segment now has knowledge of the region of space it covers
    shared_ptr<Region> segmentRegion_;
};

#endif