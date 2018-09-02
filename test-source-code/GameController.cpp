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
auto appWindow = sf::RenderWindow(sf::VideoMode(fieldWidth,fieldHeight,32), "Antipede", sf::Style::Close | sf::Style::Resize);


//function of constructor is to initialize the state of its data members
GameController::GameController() : gameIsRunning_(false), appWindow_(NULL)
{
    //initialize game objects
    field_ = new Field(800,600);
    ant_ = new Ant(380,570,20);
    segment_ = new Segment(10,10,20.f);
}

void GameController::openApplicationWindow()
{
    //Attach a window to Controller's appWindow pointer
    appWindow_ = &appWindow;
    //synchronize frame-rate to monitor's frame rate
    appWindow_->setVerticalSyncEnabled(true);
    //clear the window
    appWindow_->clear(sf::Color::Black);
    //return controller to caller
    return;
}

void GameController::displaySplashScreen()
{
    sf::Texture texture;
    if(!texture.loadFromFile("splashGround.jpg"))
    {/*do nothing for now*/}
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(260.f,60.f);
    //draw sprite
    appWindow_->draw(sprite);
    
    //write message on screen
    sf::Font   font;
    //select font for our text
    if(!font.loadFromFile("Xanadu.ttf"))
    {/*do nothing for now*/}
    
    sf::Text   splashMessage;
    splashMessage.setFont(font);
    splashMessage.setCharacterSize(30);
    splashMessage.setPosition(180.f,280.f);
    splashMessage.setFillColor(sf::Color::Green);
    splashMessage.setString("\tWelcome to Antipede!\nPress Space-Bar to start game");
    
    appWindow_->draw(splashMessage);
    
    //player keys
    sf::Font  keysFont;
    //select font for lower text
    if(!keysFont.loadFromFile("Zanes.ttf"))
    {/*do nothing for now*/}
    //
    sf::Text  playerKeys;
    playerKeys.setFont(keysFont);
    playerKeys.setCharacterSize(20);
    playerKeys.setPosition(50.f,500.f);
    playerKeys.setFillColor(sf::Color::Green);
    playerKeys.setString("\tKEYS: left-arrow | move left\tright-arrow | move right\ttop-arrow | fire bullet");
    
    appWindow_->draw(playerKeys);
    
    //player keys
    sf::Font  versionFont;
    //select font for lower text
    if(!versionFont.loadFromFile("Serifa.ttf"))
    {/*do nothing for now*/}
    //
    sf::Text  version;
    version.setFont(keysFont);
    version.setCharacterSize(15);
    version.setPosition(320.f,570.f);
    version.setFillColor(sf::Color::White);
    version.setString("\tAntipede v1.0");
    
    appWindow_->draw(version);
    
    appWindow_->display();
    //function done with its task, return control to caller
    return;
}

void GameController::playGame()
{
    //int counter = 0;
    
    //gameIsRunning_ = false;
    
    sf::Event extern_event;
    
    //while the window is open
    while(appWindow_->isOpen())
    {
        
        while(appWindow_->pollEvent(extern_event)){
            //if the triggered event is 'close window' event
            if((extern_event.type == sf::Event::Closed) || (extern_event.type == sf::Event::KeyPressed && extern_event.key.code == sf::Keyboard::Escape))
            {
                //close window
                appWindow_->close();
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
            appWindow_->clear();
        }//end event monitoring loop
        //cout << "here" << endl;
         //decide on action based on status of game, running or not
           if(gameIsRunning_){
                //....           
                //clear the window
                appWindow_->clear(Military_Green);
                //Draw Field 
                field_->drawField(appWindow_);
                //draw Ant
                ant_->drawAntOnField(appWindow_);
                //draw Segment
                segment_->drawSegmentOnField(appWindow_);
                appWindow_->display();
                //cout << counter++ << endl;;
                //gameIsRunning_ = false;
            }
            //else{}
    }//main window closed
}