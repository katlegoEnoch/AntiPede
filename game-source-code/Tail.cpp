//File_name: Tail.cpp
//Author:    Stax The Engipreneur
//Date:      12 September 2018
//Details:   Implementation of Tail member functions

#include "Tail.h"

Tail::Tail(const int& tail_x, const int& tail_y, const double& tail_size, const Direction& dir, Colour col) :
Segment(tail_x,tail_y,tail_size,dir), tail_colour_(col)
{}


Colour Tail::getTailColour() const
{
    return tail_colour_;
}
