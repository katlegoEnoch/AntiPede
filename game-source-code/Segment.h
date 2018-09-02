//File_name: Segment.h
//Author:    Stax The Engipreneur
//Date:      31 August 2018
//Details:   

#ifndef   SEGMENT_H
#define   SEGMENT_H

/*A centipede is made up of segments*/
#include <SFML/Graphics.hpp>
#include <tuple>
using namespace std;

#include "constants.h"

//empty classes representing an exceptions
class SegmentHasInvalidFieldCoordinates {};
class SegmentRadiusBeyondFieldBounds {};

class Segment{
public:
    //construct Segment object with specific location on field and size
    Segment(const int&, const int&, const double&);
    //clients of Segment can...
    void drawSegmentOnField(sf::RenderWindow* );
    tuple<int,int> getSegmentCoords() const {return {segmentX_,segmentY_};}
    //move Segment by specified amount
    void moveSegment(const int&, const int&);
    
private:
    //has a coordinate on the field
    int segmentX_;
    int segmentY_;
    //has a size i.e radius
    int segmentSize_;
};

#endif