//Filename: Centipede.cpp
//Author:   Stax The Engipreneur
//Date:     03 September 2018
//Details:  Implementation of Centipede member functions

#include "Centipede.h"
#include <iostream>
using namespace std;

Centipede::Centipede(const int& segments) : numberOfSegments_{segments}
{}

void Centipede::addSegmentToCentipede(const shared_ptr<Segment> segment)
{
    segments_.push_back(*segment);
}

void Centipede::moveCentipede(const int& speed)
{
    //for all the segments that make up the centipede
    for(size_t i = 0; i < segments_.size(); i++){
        if(segments_.at(i).onRightEdge()){
                //compute current coordinates
                auto[segX,segY] = segments_.at(i).getSegmentCoords();
                //move down one row
                segments_.at(i).moveSegment(segX,segY+1);
                //change direction
                segments_.at(i).setDirection(Direction::WEST);
                //get segment off the edge
                segments_.at(i).moveSegment(-1,0);
            }
            else if(segments_.at(i).onLeftEdge()){
                //compute current coordinates
                auto[segX,segY] = segments_.at(i).getSegmentCoords();
                //move down one row
                segments_.at(i).moveSegment(segX,segY+1);
                //change direction
                segments_.at(i).setDirection(Direction::EAST);
                //move segment by one unit to right
                segments_.at(i).moveSegment(1,0);//get it off the edge
            }
            else{//segment is on neither edge
                //move segment in direction
                segments_.at(i).move(speed,segments_.at(i).getDirection());
            }
    }
}

void Centipede::destroySegmentAt(const int& position)
{
//    segments_.erase()
}



