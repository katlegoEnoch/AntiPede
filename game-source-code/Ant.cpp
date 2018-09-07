//Filename: Ant.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  

#include "Ant.h"

Ant::Ant(const int& antX, const int& antY, const double& ant_size) : antX_{antX}, antY_{antY}, antSize_{ant_size}
{
     //if either boundary is beyond limits of the screen...
    if((antX_ < 0 || antX_ > fieldWidth) || (antY_ < 0 || antY_ > fieldHeight))
    {
        //throw exception
        throw AntCoordinatesOutOfFieldBounds{};
    }
    
    //ant size must be within 20% of field dimensions or else is considered too big for interesting game play
    //size of ant is limited
    if(antSize_ > 0.2*fieldWidth || antSize_ > 0.2*fieldHeight)
    {
        //throw exception if an attempt is made to construct is large ant
        throw AntSizeBeyondFieldBounds{};
    }
        
}

void Ant::moveAnt(int deltaX, int deltaY)
{
   auto left_edge = fieldWidth - (10+antSize_);
   auto right_edge = 10;
    
    //if movement is to the right
    if(deltaX > 0){
        if(antX_ == left_edge){
        antX_ = antX_;
        }
        else{
        //change ant's x position by deltaX
        antX_+= deltaX;
        }
    }//end if
    else{//if movement is to the left
        if(antX_ == right_edge){
            antX_ = antX_;
        }
        else
            antX_ += deltaX;
    }
    
    //change ant's y position by deltaY
    antY_ += deltaY;
}

//initializes the gun
void Ant::loadWeapon()
{
    //call the gun constructor to place gun on top of ant
    Gun gun(antX_+(antSize_/2),antY_);
}

