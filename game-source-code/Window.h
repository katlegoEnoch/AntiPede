//File_name: Window.h
//Author:    Stax The Engipreneur
//Date:      03 September 2018
//Details:   Header file for Window class

#ifndef WINDOW_H
#define WINDOW_H

/*interface between window and program*/

#include <SFML/Graphics.hpp>

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "constants.h"

class Window{
public:
    //create a window with specific dimensions
    Window(const size_t&, const size_t&);
    //get screen dimensions
    size_t windowWidth() const {return window_width_;}
    size_t windowHeight() const {return window_height_;}
      //get window
    sf::RenderWindow* getWindow();
    
    //concealed library functions
    void syncWindowToMonitor() const;
    void clearWindow(const Colour&);
    bool windowIsOpen();
    void showContents();
    void shutDownWindow();
    bool queryEvent(sf::Event&);

private:
    //Window has height
    size_t window_width_;
    size_t window_height_;
    //has a window
    static sf::RenderWindow* window_;
};

#endif