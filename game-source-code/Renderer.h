//File_name: Renderer.h
//Author:    Stax The Engipreneur
//Date:      03 September 2018
//Details:  

/*Class is responsible for drawing game objects on the window*/

#ifndef RENDERER_H
#define RENDERER_H


#include "Field.h"
#include "Ant.h"
#include "Segment.h"
#include "Centipede.h"
#include "Window.h"

class Renderer{
    
public:
    //create a Renderer object and attach a window to it
    Renderer(Window*);

    void drawField(const Field*);
    void drawAntOnField(const Ant*);
    void drawCentipede(const Centipede* );
    void drawSegmentOnField(const Segment& );//had to be passed by reference
    
private:

    //has window that is draws on
    Window* window_;
};

#endif