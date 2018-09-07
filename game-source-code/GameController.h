//Filename: GameController.h
//Author:   Stax The Engipreneur
//Date:     31 August 2018
//Details:  

#ifndef  GAMECONTROLLER_H
#define  GAMECONTROLLER_H

#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include "Field.h"
#include "Ant.h"
#include "Segment.h"
#include "constants.h"
#include "Centipede.h"
#include "Renderer.h"
#include "Window.h"
#include "ScreenSplasher.h"
#include "EventsHandler.h"
#include "Resource.h"

class GameController{
    
public:
    GameController();
    //clients of GameController can...
    //Open application window
    void openApplicationWindow();
    //display the splash screen
    void displaySplashScreen();
    //play the game
    void playGame();
    
private:
    //private helper functions
    void drawGameObjects();
    void updateGameObjects();
    //maintains all the game objects in its memory
    shared_ptr<Field> field_;
    shared_ptr<Ant> ant_;
    shared_ptr<Segment> segment_;
    shared_ptr<Centipede> centipede_;
    shared_ptr<Renderer> renderer_;
    shared_ptr<Window> appWindow_;
    shared_ptr<Resource> resource_;
    shared_ptr<EventsHandler> event_;
    //shared_ptr<EventsHandler> event_;
    //additional variables
    bool gameIsRunning_; //keeps record of game status
};

#endif