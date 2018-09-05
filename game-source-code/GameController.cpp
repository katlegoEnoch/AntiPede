//File_name: GameController.cpp
//Author:    Stax The Engipreneur
//Date:      31 August 2018
//Details:   

#include "GameController.h"
#include <SFML/Graphics.hpp>

//#include "GameConstants.h"


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
    
    sf::Event extern_event;
    
    //while the window is open
    while(appWindow_->getWindow()->isOpen())
    {
        //move segment by pixel to right each time we loop, that's too fast, the screen is too small.
        if(gameIsRunning_){
            //move Centipede
            centipede_->moveCentipede(5);
            
        }
        while(appWindow_->getWindow()->pollEvent(extern_event)){
            //if the triggered event is 'close window' event
            if((extern_event.type == sf::Event::Closed) || (extern_event.type == sf::Event::KeyPressed && extern_event.key.code == sf::Keyboard::Escape))
            {
                //close window
                appWindow_->getWindow()->close();
                //break out of the event monitoring loop,
                break;
            }//end if
            
            //if event noted is keyboard event and key pressed is space
            if(extern_event.type == sf::Event::KeyPressed && extern_event.key.code == sf::Keyboard::Space){
                //set gameRunning flag if it wasn't
                if(!gameIsRunning_){
                    gameIsRunning_ = true;
                }
                
            }//end if
            
                if(extern_event.type == sf::Event::KeyPressed && extern_event.key.code == sf::Keyboard::Right)
                {
                    ant_->moveAnt(10,0);
                }
                if(extern_event.type == sf::Event::KeyPressed && extern_event.key.code == sf::Keyboard::Left)
                {
                    ant_->moveAnt(-10,0);
                }
            
            //display the window
            //appWindow_->display();
            appWindow_->getWindow()->clear();
        }//end event monitoring loop
         //decide on action based on status of game, running or not
           if(gameIsRunning_){
                //....           
                //clear the window
                appWindow_->getWindow()->clear(Military_Green);
                //Draw Field 
                renderer_->drawField(field_);
                //draw Ant
                renderer_->drawAntOnField(ant_);
                //draw Centipede
                renderer_->drawCentipede(centipede_);
                appWindow_->getWindow()->display();
                //cout << counter++ << endl;;
                //gameIsRunning_ = false;
            }
            //else{}
    }//main window closed
}