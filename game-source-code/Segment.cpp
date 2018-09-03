//Filename: Segment.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  Implementation of Segment member functions

#include "Segment.h"

#include <iostream>
using namespace std;

Segment::Segment(const int& segX, const int& segY, const double& segSize, const Direction& segDir) : segmentX_{segX}, segmentY_{segY}, segmentSize_{segSize}, segmentDir_{segDir} 
{
    //compare segment coordinates to field boundaries
    if((segmentX_ < 0 || segmentX_ > fieldWidth) || (segmentY_ < 0 || segmentY_ > fieldHeight))
    {
        throw SegmentHasInvalidFieldCoordinates{};
    }
    
    //a realistic segment is at most 10% the area of the field
    if(segmentSize_ > 0.1*fieldHeight || segmentSize_ > 0.1*fieldWidth)
    {
        throw SegmentRadiusBeyondFieldBounds{};
    }
}

void Segment::moveSegment(const int& deltaX,const int& deltaY)
{
    auto right_edge = fieldWidth - 30;
    auto left_edge = 10;
    //for right movements
    if(deltaX>0){
        if(segmentX_ == right_edge){
            segmentX_ = segmentX_;
            segmentY_ += deltaY;
        }//end if
        else{
            segmentX_ += deltaX;
            segmentY_ = segmentY_;
        }
    }//end if
    else{//for left movements
        if(segmentX_ == left_edge){
            segmentX_ = segmentX_;
            segmentY_ += deltaY;
            cout << "left edge" << endl;
        }//end if
        else{
            segmentX_ += deltaX;
            segmentY_  = segmentY_;
        }
    }
   
}

bool Segment::onRightEdge() const
{
    if(segmentX_ == fieldWidth - 30)
        return true;
    else
        return false;
}

bool Segment::onLeftEdge() const
{
    if(segmentX_ == 10)
        return true;
    else
        return false;
}
 
//move direction in specified direction by specified amount
void Segment::move(const int& steps, const Direction& dir)
{
    //cout << "I'm here" << endl;
    
    if(dir == Direction::EAST)
        segmentX_ += steps;
    else if(dir == Direction::WEST){
        segmentX_ -= steps;
    }
}