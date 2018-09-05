//File_name: GameController.cpp
//Author:    Stax The Engipreneur
//Date:      31 August 2018
//Details:   

#include "GameController.h"

#include <iostream>
using namespace std;

/*Ran into scope issues and window was only open in the function in which the renderWindow function is called*/
//window dimensions



//function of constructor is to initialize the state of its data members
GameController::GameController() : gameIsRunning_(false)
{
    //ensure that ant starts at centre of bottom row
    
    //initialize field
    field_ = make_shared<Field>(fieldWidth,fieldHeight);
    
    //initialize Ant
    auto ant_x = static_cast<int>((fieldWidth/2)-20);
    auto ant_y = fieldHeight - 30;
    ant_ = make_shared<Ant>(ant_x,ant_y,20);
    
    //construct Centipede with 10 segments
    centipede_ = make_shared<Centipede>(10);
    //Centipede always starts at top left of field
    auto seg_x = 11;
    auto seg_y = 10;
    //add segments to Centipede
    for(size_t cent_elmnt = 0; cent_elmnt < centipede_->numberOfSegments();cent_elmnt++){
        if(cent_elmnt != 0){
            //create segment
            auto segment = make_shared<Segment>(seg_x+((cent_elmnt)*20),seg_y,10.f,Direction::EAST);
            //add segment to Centipeded
            centipede_->addSegmentToCentipede(segment);
        }//end if
        else{
            auto segment = make_shared<Segment>(seg_x,seg_y,10.f,Direction::EAST);
            //add segment to Centipeded
            centipede_->addSegmentToCentipede(segment);
        }//end else
    }//end loop
    
    //create a window
    appWindow_ = make_shared<Window>(300,300);
    //create resource
    resource_ = make_shared<Resource>();
    
    //create a renderer and initialize its window
    renderer_ = make_shared<Renderer>(appWindow_);
    
    //create event handler
    event_ = make_shared<EventsHandler>();
}

void GameController::openApplicationWindow()
{
    
    //Attach a window to Controller's appWindow pointer
    //synchronize frame-rate to monitor's frame rate
    appWindow_->getWindow()->setVerticalSyncEnabled(true);
    //clear the window
    appWindow_->getWindow()->clear(sf::Color::Black);
    //return controller to caller
    
    return;
}

void GameController::displaySplashScreen()
{
    //create ScreenSplasher object and pass window
    ScreenSplasher splasher(appWindow_,resource_);
    //command object to display splash screen
    splasher.displaySplashScreen();
}

void GameController::playGame()
{
    //while the window is open
    while(appWindow_->getWindow()->isOpen())
    {
        //cout << "looping" << endl;
        
        //move segment by pixel to right each time we loop, that's too fast, the screen is too small.
        if(gameIsRunning_){
            //move Centipede
            centipede_->moveCentipede(5);
        }
        while(appWindow_->getWindow()->pollEvent(*(event_->getEvent()))){
            //update objects based on inputs
            updateGameObjects();
            appWindow_->getWindow()->clear();
        }//end event monitoring loop
         //decide on action based on status of game, running or not
           if(gameIsRunning_){
                drawGameObjects();
            }
    }//main window closed
}

void GameController::drawGameObjects()
{
    //clear the window
    appWindow_->getWindow()->clear(Military_Green);
    //Draw Field 
    renderer_->drawField(field_);
    //draw Ant
    renderer_->drawAntOnField(ant_);
    //draw Centipede
    renderer_->drawCentipede(centipede_);
    
    appWindow_->getWindow()->display();
}

void GameController::updateGameObjects()
{
    //process event
    switch(event_->processEvent()){
        case KeyCode::CLOSE_WINDOW:
            //close window
            if(!gameIsRunning_){
            //appWindow_->getWindow()->close();
            }
            break;
        case KeyCode::START_GAME:
            //start_game
            if(!gameIsRunning_){
                gameIsRunning_ = true;
            }
            break;
        case KeyCode::MOVE_ANT_LEFT:
            //move ant left
            ant_->moveAnt(-10,0);
            break;
            case KeyCode::MOVE_ANT_RIGHT:
            //move ant right
            ant_->moveAnt(10,0);
            break;
        case KeyCode::FIRE_BULLET:
            //do nothing for now
            break;
        case KeyCode::IGNORE:
            //
            gameIsRunning_ = false;
            //default:
            //do nothing
            //break;
    }//end switch
}