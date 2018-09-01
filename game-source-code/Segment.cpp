//Filename: Segment.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  Implementation of Segment member functions

#include "Segment.h"

Segment::Segment(const int& segX, const int& segY) : segmentX_(segX), segmentY_(segY)
{}

void Segment::drawSegmentOnField(sf::RenderWindow* window)
{
    sf::CircleShape segment(10);
    segment.setFillColor(sf::Color::Red);
    segment.setPosition(segmentX_,segmentY_);
    
    window->draw(segment);
    
    //return control to caller
    return;
}