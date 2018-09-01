//Filename: Field.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  Implementation of Field member functions

#include "Field.h"

void Field::drawField(sf::RenderWindow* window)
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(800,600));
    rect.setOutlineThickness(-10);
    rect.setFillColor(sf::Color(78,86,35));
    rect.setOutlineColor(sf::Color(70,50,30));
    
    window->draw(rect);
    
    //return control to caller;
    return;
}