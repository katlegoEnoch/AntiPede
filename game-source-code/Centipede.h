//Filename: Centipede.h
//Author:   Stax The Engipreneur
//Date:     03 September 2018
//Details:  Header file for Centipede object

#ifndef CENTIPEDE_H
#define CENTIPEDE_H


#include "Segment.h"
#include <vector>
using namespace std;

/*The centipede can be responsible for controlling its segments'movement. The segments move themselves
 but the centipede controls the movement.*/
 
 
class Centipede{
    
public:
    //responsible for controlling each of its segment's movement
    void moveCentipede();
    void addSegmentToCentipede(const Segment* );
    void drawCentipede(sf::RenderWindow* );

private:
//a centipede has a number of segments that it maintains in its memory
    vector<Segment> segments_;
    
};//end Centipede class definition

#endif