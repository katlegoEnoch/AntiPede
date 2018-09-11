//File_name: Head.cpp
//Author:    Stax The Engipreneur
//Date:      11 September 2018
//Details:   

#include "Head.h"

Head::Head(const int& head_x, const int& head_y, const double& head_size, const Direction& dir, Colour col) :
Segment(head_x,head_y,head_size,dir), head_colour_(col)
{}


Colour Head::getHeadColour() const
{
    return head_colour_;
}
