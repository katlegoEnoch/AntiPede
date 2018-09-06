//Filename: Window.cpp
//Author:   Stax The Engipreneur
//Date:     03 September 2018
//Details:  Implementation of Window's member function

#include "Window.h"
#include "constants.h"

#include <iostream>
using namespace std;

auto window = sf::RenderWindow(sf::VideoMode(fieldWidth,fieldHeight,32), "ANTIpede");

Window::Window(const size_t& width, const size_t& height) : window_width_{width}, window_height_{height}
{
    window_ = &window;
}

