//Filename: Segment.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  Implementation of Segment member functions

#include "Segment.h"

Segment::Segment(const int& segX, const int& segY, const double& segSize) : segmentX_{segX}, segmentY_{segY}, segmentSize_{segSize} 
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

void Segment::drawSegmentOnField(sf::RenderWindow* window)
{
    sf::CircleShape segment(segmentSize_);
    segment.setFillColor(sf::Color::Red);
    segment.setPosition(segmentX_,segmentY_);
    
    window->draw(segment);
    
    //return control to caller
    return;
}

void Segment::moveSegment(const int& deltaX,const int& deltaY)
{
    auto right_edge = fieldWidth - 30;
    auto left_edge = 10;
    //for right movements
    if(deltaX>0){
        if(segmentX_ == right_edge){
            segmentX_ = segmentX_;
            segmentY_ += 1;
        }//end if
        else{
            segmentX_ += deltaX;
            segmentY_ = segmentY_;
        }
    }//end if
    else{//for left movements
        if(segmentX_ == left_edge){
            segmentX_ = segmentX_;
            segmentY_ += 1;
        }//end if
        else{
            segmentX_ += deltaX;
            segmentY_  = segmentY_;
        }
    }
}