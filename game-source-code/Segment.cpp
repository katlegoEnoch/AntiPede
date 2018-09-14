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
    
    //a realistic segment is at most 50% the area of the field
    if(segmentSize_ > 0.5*fieldHeight || segmentSize_ > 0.5*fieldWidth)
    {
        throw SegmentRadiusBeyondFieldBounds{};
    }
    
    //segment starts out alive
    segmentAlive_ = true;
}

void Segment::moveSegment(const int& deltaX,const int& deltaY)
{
    auto right_edge = fieldWidth - 30;
    auto left_edge = 10;
    
    if(segmentX_ == left_edge)
    {
        if(!(segmentX_ <= left_edge)){
            segmentX_ = segmentX_;
            segmentY_ += 15;
        }
        else{
            segmentX_ = left_edge;
            segmentY_ += 15;
        }
    }
    
    //for right movements
    if(deltaX>0){
        if(segmentX_ == right_edge){
            if(!(segmentX_ >= right_edge)){
                segmentX_ = segmentX_;
                segmentY_ += 15;
            }
            else{
                segmentX_ = right_edge;
                segmentY_ += 15;
            }
        }//end if
        else{
            segmentX_ += deltaX;
            segmentY_ = segmentY_;
        }
    }//end if
    else {//for left movements
        if(segmentX_ == 10){
            segmentX_ = segmentX_;
            //segmentY_ += 2;
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
    auto right_edge = fieldWidth - 30;
    auto left_edge = 10;
    
    if(dir == Direction::EAST){
        if((segmentX_+steps) <= right_edge)
            segmentX_ += steps;
        else
            segmentX_ = right_edge;
    }
    else if(dir == Direction::WEST){
        if((segmentX_-steps >= left_edge))
            segmentX_ -= steps;
        else
            segmentX_ = left_edge;
    }
}

void Segment::setSegmentState(bool state)
{
    segmentAlive_ = state;
}


//each segment now has knowledge of the region of space it covers on the field and is able to share this info with clients
shared_ptr<Region> Segment::computeSegmentRegion()
{
    //compute max and min values based on segment's current position
    auto minValue = segmentX_ - segmentSize_;
    auto maxValue = segmentX_ + segmentSize_;
      //check that computed values are within bounds
    if(minValue < 0){
        //replace with zero
        minValue = 0;
    }
    if(maxValue > fieldWidth){
        //set to maximum
        maxValue = fieldWidth;
    }
    //construct a region object based on value and pass to caller
    segmentRegion_ = make_shared<Region>(minValue,maxValue,segmentX_);
    return segmentRegion_;
}

void Segment::crownSegment(const Crown crown)
{
    seg_crown_ = crown;
}