//Filename: AreaCovered.h
//Author:   Stax The Engipreneur
//Date:     09 September 2018
//Details:  

#ifndef  AREACOVERED_H
#define  AREACOVERED_H

#include "constants.h"

/*each game object occupies a certain area on the field.*/
class AreaBeyondFieldBoundary {};

class AreaCovered{
public:
    AreaCovered(const double&, const double&);
    //compute area covered by object
    double computeAreaCovered();
    
private:
    double minValue_;
    double maxValue_;
};

#endif