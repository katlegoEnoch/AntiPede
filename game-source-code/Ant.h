//File_name: Ant.h
//Author:    Stax The Engipreneur
//Date:      31 August 2018
//Details:   Definition of Ant Model

/*An ant fires bullets at the centipede*/
#ifndef  ANT_H
#define  ANT_H


#include <tuple>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Field.h"
#include "constants.h"
#include "Gun.h"

class AntCoordinatesOutOfFieldBounds {};
class AntSizeBeyondFieldBounds{};

class Ant{
    
public:
    //instatiated with specific position on the field and size
    Ant(const int&, const int&, const double&);
    //clients of Ant object can...
    //move ant by x units, left or right, and y units, up or down
    void moveAnt(int, int);
    //receive coordinates of ant on the field
    tuple<int,int> getAntCoords() const {return {antX_,antY_};}
    //get size of ant
    double getAntSize() const {return antSize_;}
    //members manipulating ant's gun
    //the guns's location is always relative to the ant
    //initializes the ant's weapon - gun
    void loadWeapon();
    //access the ant's gun
    shared_ptr<Gun> getGun() const { return gun_;}

    
private:
    //an ant has a position on the field
    int antX_;
    int antY_;
    //the ant, modelled as a square, has a size which is simply the length of a side
    double antSize_;
    //ant carries a gun
    static shared_ptr<Gun> gun_;
};

#endif