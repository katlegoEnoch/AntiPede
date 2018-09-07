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
#include "Gun.h"

class Renderer{
    
public:
    //create a Renderer object and attach a window to it
    Renderer(shared_ptr<Window>);//couldn't make Window constant

    void drawField(const shared_ptr<Field>);
    void drawAntOnField(const shared_ptr<Ant>);
    void drawCentipede(const shared_ptr<Centipede>);
    void drawGun(const shared_ptr<Gun>);
    void drawBullet(const Bullet&);//had to change this to a constant reference, doesn't work well with pointers
    
private:
    //not required be external objects, helper to drawCentipede member
    void drawSegmentOnField(const Segment& );//had to be passed by reference

    //has window that is draws on
    shared_ptr<Window> window_;
};

#endif