//Filename: Field.h
//Author:   Stax The Engipreneur
//Date:     31 August 2018
//Details:  

#ifndef  FIELD_H
#define  FIELD_H

#include <tuple>
using namespace std;

#include "constants.h"

class FieldOutOfScreenBounds {};


/*The field is the region where the centipede and the ant come head to head*/

class Field{
public:
    //Field object instantiated with boundary
    Field(const int&, const int&);
    //Field object can be queryied what its boundary co-ordinates are
    tuple<int,int> fieldBoundary() const;
    //accessors
private:
    //field has a boundary
    int boundary_x;
    int boundary_y;
};

#endif