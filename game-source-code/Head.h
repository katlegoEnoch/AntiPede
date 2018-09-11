//File_name: Head.h
//Author:    Stax The Engipreneur
//Date:      11 September 2018
//Details:   Head is derived from Segment class

#ifndef HEAD_H
#define HEAD_H

#include "Segment.h"
#include "constants.h"

class Head : public Segment{
public:
    Head(const int&, const int&, const double&, const Direction&, Colour);
    Colour getHeadColour() const;
private:
    //has a colour
    Colour head_colour_;
    
};//

#endif