//Filename: Window.cpp
//Author:   Stax The Engipreneur
//Date:     03 September 2018
//Details:  Implementation of Window's member function

#include "Window.h"
#include "constants.h"

auto window = sf::RenderWindow(sf::VideoMode(fieldWidth,fieldHeight,32), "Antipede");

Window::Window(const int& width, const int& height) : window_width_{width}, window_height_(height)
{
    
    window_ = &window;
}

