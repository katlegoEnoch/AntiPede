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
    
    //initialize Ant, when Ant constructor is called, gun is automatically created
    //Ant has handle to its gun
    auto ant_size = 20;
    auto ant_x = static_cast<int>((fieldWidth/2)-20);
    auto ant_y = fieldHeight - (ant_size+10);
    ant_ = make_shared<Ant>(ant_x,ant_y,ant_size);
    
    //
    
    //construct Centipede with 10 segments
    auto numberOfSegments = 15;
    centipede_ = make_shared<Centipede>(numberOfSegments);
    //Centipede always starts at top left of field
    auto seg_x = 11;//11
    auto seg_y = 10;//fieldHeight -(ant_size+60);//10;
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
    appWindow_->syncWindowToMonitor();
    //clear the window
    appWindow_->clearWindow(Colour::BLACK_);
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
    while(appWindow_->windowIsOpen())
    {
        //fire from here
        if(!bullets_.empty()){
            fireBullet();
        }
        
        //for all the segments in the centipede
        for(size_t centLoc = 0; centLoc < centipede_->numberOfSegments();centLoc++){
            //inner loop - for all the bullets
            for(size_t bulloc = 0; bulloc < bullets_.size();bulloc++){
                //calculate size of region surrounding bullet
                auto bul_reg = bullets_.at(bulloc).computeBulletRegion();
                //calculate region of region surrounding segment
                auto seg_reg = centipede_->getSegmentAt(centLoc).computeSegmentRegion();
                //compute a mactch between the two regions, if there's a match
                if(!bullets_.empty()){
                    //compare the heights
                    if(computeMatch(seg_reg,bul_reg)){
                        //if the heights also match
                        if(bullets_.at(bulloc).getBulletHeight() == centipede_->getSegmentAt(centLoc).getSegmentHeight()){
                            //change the current segment's state to false
                            centipede_->getSegmentAt(centLoc).setSegmentState(false);
                            //change current bullet's state to false as well;
                            bullets_.at(bulloc).setBulletState(true);
                        }//end if
                        
                    }//end if
                }//end if
            }//end inner loop
        }//end outer for loop
        

        //move segment by pixel to right each time we loop, that's too fast, the screen is too small.
        if(gameIsRunning_){
            //move Centipede
            centipede_->moveCentipede(0);
        }
        while(appWindow_->queryEvent(*(event_->getEvent()))){
            //update objects based on inputs
            updateGameObjects();
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
    appWindow_->clearWindow(Colour::M_GREEN_);
    //Draw Field 
    renderer_->drawField(field_);
    //draw Ant
    renderer_->drawAntOnField(ant_);
    //draw Gun
    //Gun is accessed through Ant
    renderer_->drawGun(ant_->getGun());
    //draw Centipede
    renderer_->drawCentipede(centipede_);
    //draw Bullet, accessed through its owner ant
    renderer_->drawBullets(bullets_);
    appWindow_->showContents();
}

void GameController::updateGameObjects()
{
    //process event
    switch(event_->processEvent()){
        case KeyCode::CLOSE_WINDOW:
            //close window
            if(gameIsRunning_){
                //window not closing properly
            }
            break;
        case KeyCode::START_GAME:
            //start_game
            if(!gameIsRunning_){
                gameIsRunning_ = true;
            }
            break;
        case KeyCode::END_GAME:
            //close window
            appWindow_->shutDownWindow();
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
            //create bullet object
            ant_->setBullet(ant_->releaseBullet());
            //add bullet to Controller's memory
            addBulletToController(ant_->releaseBullet());
            break;
        case KeyCode::IGNORE_INPUT:
            //
            gameIsRunning_ = false;
        default:
            //do nothing
            gameIsRunning_ = true;
            break;
    }//end switch
}


void GameController::addBulletToController(const Bullet& bullet)
{
    bullets_.push_back(bullet);
}

//how about implementing the fire bullet function on the controller and not the ant?
//if that was the case then...
void GameController::fireBullet()
{
    //at the moment a Bullet is created it should start moving upward
    for(size_t loc = 0; loc < bullets_.size();loc++){
        //move the corresponding bullet
        bullets_.at(loc).moveBullet(8,Direction::NORTH);
    }
}
//yes it worked! So the ant and the controller pretty much share the responsibility of the bullet's behaviour
//the bullet is an inanimate object and does not control itself, the ant controls the bullet.


bool GameController::computeMatch(shared_ptr<Region> segment,shared_ptr<Region> bullet)
{
    //extrac values from pointers passed in
    auto segRegionMax = segment->getRegionMax();
    auto segRegionMin = segment->getRegionMin();
    auto segCenter = segment->getCenter();
    auto bullRegionMax = bullet->getRegionMax();
    auto bullRegionMin = bullet->getRegionMin();
    auto bulCenter = bullet->getCenter();
    
    //radius for segment and center can be computed
    auto segRad = segRegionMax - segRegionMin;
    auto bulRad = bullRegionMax - bullRegionMin;    
    //compute degree of match
    //for bullet on left of segment
    
    if(bulCenter < segCenter){
        if((bulCenter+bulRad) < (segCenter-segRad)){
            return false;
        }//end if
        else
            return true;
    }// end if
    else if(bulCenter > segCenter){
        //for bullet to right of segment
        if((segCenter+bulRad) < (bulCenter-bulRad)){
            return false;
        }
        else
            return true;
    }// end else if
    //bullet on left or right of segment
    else if(((bulCenter+bulRad) >= (segCenter-segRad)) || ((bulCenter - bulRad) <= (segCenter+segRad)))
        return true;
    else
        return false;
    
}