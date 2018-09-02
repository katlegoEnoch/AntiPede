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