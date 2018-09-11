//File_name: Tail.h
//Author:    Stax The Engipreneur
//Date:      12 September 2018
//Details:   

#ifndef TAIL_H
#define TAIL_H

#include "Segment.h"
#include "constants.h"

class Tail : public Segment{
public:
    Tail(const int&, const int&, const double&, const Direction&, Colour);
    Colour getTailColour() const;
private:
    //has a colour
    Colour tail_colour_;
    
};//

#endif