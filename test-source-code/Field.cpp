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

void Field::drawField(sf::RenderWindow* window)
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(boundary_x,boundary_y));
    rect.setOutlineThickness(-10);
    rect.setFillColor(sf::Color(78,86,35));
    rect.setOutlineColor(sf::Color(70,50,30));
    
    window->draw(rect);
    
    //return control to caller;
    return;
}

tuple<int,int> Field::fieldBoundary() const
{
    return {boundary_x,boundary_y};
}