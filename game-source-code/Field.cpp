//Filename: Field.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  Implementation of Field member functions

#include "Field.h"


Field::Field(const int& edge_x, const int& edge_y) : boundary_x{edge_x}, boundary_y{edge_y}
{
    //if either boundary is beyond limits of the screen...
    if((boundary_x < 0 || boundary_x > fieldWidth) || (boundary_y < 0 || boundary_y > fieldHeight))
    {
        //throw exception
        throw FieldOutOfScreenBounds{};
    }
} 

tuple<int,int> Field::fieldBoundary() const
{
    return {boundary_x,boundary_y};
}