//Filename: Window.cpp
//Author:   Stax The Engipreneur
//Date:     03 September 2018
//Details:  Implementation of Window's member function

#include "Window.h"
#include "constants.h"

//static data member
sf::RenderWindow* Window::window_ = NULL;

auto window = sf::RenderWindow(sf::VideoMode(fieldWidth,fieldHeight,32), "ANTIpede");

Window::Window(const size_t& width, const size_t& height) : window_width_{width}, window_height_{height}
{
   
    window_ = &window;
}

sf::RenderWindow* Window::getWindow()
{
    return window_;
}

void Window::syncWindowToMonitor() const
{
    window_->setVerticalSyncEnabled(true);
}

void Window::clearWindow(const Colour& color)
{
    switch(color){
        case Colour::M_GREEN_:
            window_->clear(M_GREEN);
            break;
        case Colour::RED_:
            window_->clear(RED);
            break;
        case Colour::BLUE_:
            window_->clear(BLUE);
            break;
        case Colour::GREEN_:
            window_->clear(GREEN);
            break;
        case Colour::YELLOW_:
            window_->clear(YELLOW);
            break;
        case Colour::TURQUOISE_:
            window_->clear(TURQUOISE);
            break;
        case Colour::VIOLET_:
            window_->clear(VIOLET);
            break;
        case Colour::BLACK_:
            window_->clear(BLACK);
            break;
        case Colour::WHITE_:
            window_->clear(WHITE);
            break;
        case Colour::SILVER_:
            window_->clear(SILVER);
            break;
        case Colour::GREY_:
            window_->clear(GREY);
            break;
        default:
            window_->clear(BLACK);
            break;
    }//end switch
}

bool Window::windowIsOpen()
{
    return window_->isOpen();
}

bool Window::queryEvent(sf::Event& evnt)
{
    if(window_->pollEvent(evnt))
    {
        return true;
    }
    else
        return false;
}

void Window::showContents()
{
    window_->display();
}

void Window::shutDownWindow()
{
    window_->close();
}

