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

#include <vector>
using std::vector;

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
//Controller can maintain a vector of bullet
#include "Bullet.h"
#include "CollisionDetector.h"
//controller needs direct access to bullet
//how about accessing the bullet throught the ant? That's the way
//#include "Bullet.h"

enum class Sensitivity{LOW,MEDIUM,HIGH};

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
    //maintain set of bullets in memory
    void addBulletToController(const Bullet&);
    //ant can pass a message onto its bullet to move
    void fireBullet();
    
private:
    //private initialization functions
    shared_ptr<Ant> initializeAnt() const;
    shared_ptr<Centipede> initializeCentipede() const;
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
    //additional variables
    bool gameIsRunning_; //keeps record of game status
    //to fix firing problem
    vector<Bullet> bullets_;
    shared_ptr<CollisionDetector> detector_;
    //now game controller has centipedes
    vector<shared_ptr<Centipede>> centipedes_;
    //static variable
    int collisionCount_;
};

#endif