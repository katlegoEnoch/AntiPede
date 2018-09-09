//File_name: Region.h
//Author:    Stax The Engipreneur
//Date:      09 September 2018
//Details:   Header file for user defined type called Range

/*Each game object will have a region that it covers. A bullet will have a region. A segment will have a region and so will the centipede as well as the bullet and the mushroom.
 The purpose of this class is to model the concept of region which is basically a range of points that fall within some boundary. Game objects will use this object. The main idea
  is that game object should be self-aware, intelligent object. They shouldn't have to depend on external sources to know their surroundings. Each object will have a region that 
  it covers and must know when other game object have entered this region. More will be mentioned in the code. We are using simple circles to model game objects*/
 

#ifndef FIELDREGION_H
#define FIELDREGION_H  

#include "constants.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

class RegionBeyondFieldBoundary {};

//at this point we are only interested in the horizontal range - vertical range is not important for the interaction between the bullet and the segment owing to the fact that the 
//bullet travels in a straight line


class Region{
    
public:
    //a region object is created with a maximum value and a mininum value
    Region(const int&, const int&);
    //handlers
    int getRegionMax() const {return region_max_;}
    int getRegionMin() const {return region_min_;}
    
private:
    //a region has...
    int region_min_; //minimum value - to the left of the center
    int region_max_;//maximum value - to the right of the center
};

/*Each game object will need to maintain a record of its region. We will have a Bullet object having Region data member and providing its clients access to via a pointer. Each object will need to keep
 * calculating its range based on its current x-position and must have an ability to communicate that range to other objects so that comparisons can be made*/


#endif

