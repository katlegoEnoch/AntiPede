//File_name: ScreenSplasher.h
//Author:    Stax The Engipreneur
//Date:      04 September 2018
//Details:   Headerfile of object responsible for display Splashscreen and all of its contents

#ifndef SCREENSPLASHER_H
#define SCREENSPLASHER_H

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include "Resource.h"
#include "Window.h"
#include "constants.h"

class ScreenSplasher{
public:
    ScreenSplasher(shared_ptr<Window>,shared_ptr<Resource>);
    void displaySplashScreen();
private:
    //private helper functions
    void printMainText();
    void displayImage();
    void printKeysText();
    void printVersionText();
    //should also have a Window
    shared_ptr<Window> window_;
    //a Screen splasher has a resource that grants access to encapsulated SFML resources
    shared_ptr<Resource> resource_;
    
};//end of class definition

#endif