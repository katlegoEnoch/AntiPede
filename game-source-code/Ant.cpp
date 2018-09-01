//Filename: Ant.cpp
//Author:   Stax The Engipreneur
//Date:     01 September 2018
//Details:  


#include "Ant.h"

Ant::Ant(const int& antX, const int& antY) : antX_(antX), antY_(antY)
{}

void Ant::drawAntOnField(sf::RenderWindow* window)
{
    sf::RectangleShape ant;
    ant.setSize(sf::Vector2f(20,20));
    ant.setPosition(antX_,antY_);
    ant.setFillColor(sf::Color::Green);
    
    window->draw(ant);
}

void Ant::moveAnt(int deltaX, int deltaY)
{
    antX_+= deltaX;
    antY_ += deltaY;
}