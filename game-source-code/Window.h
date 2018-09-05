//File_name: Window.h
//Author:    Stax The Engipreneur
//Date:      03 September 2018
//Details:   Header file for Window class

#ifndef WINDOW_H
#define WINDOW_H

/*interface between window and program*/

//#include <memory>
//using std::shared_ptr;
//using std::make_shared;

#include <SFML/Graphics.hpp>

class Window{
public:
    //create a window with specific dimensions
    Window(const int&, const int&);
    //get screen dimensions
    size_t windowWidth() const {return window_width_;}
    size_t windowHeight() const {return window_height_;}
      //get window
    sf::RenderWindow* getWindow() const {return window_;}

private:
    //Window has height
    size_t window_height_;
    size_t window_width_;
    //has a window
    sf::RenderWindow* window_;
    
};

#endif