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
    //local variables - 
    //ensure that ant starts at centre of bottom row
    auto ant_x = static_cast<int>((fieldWidth/2)-20);
    auto ant_y = fieldHeight - 30;
    
    //segment always starts at top left of field
    auto seg_x = 10;
    auto seg_y = 10;
    
    //initialize game objects
    field_ = new Field(fieldWidth,fieldHeight);
    
    ant_ = new Ant(ant_x,ant_y,20);
    segment_ = new Segment(seg_x,seg_y,10.f,Direction::EAST);
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
    //local variables to ensure that sizes are relative to screen dimensions
    auto charSize =        static_cast<int>((fieldWidth+fieldHeight)/47);
    auto versionCharSize = static_cast<int>((fieldWidth+fieldHeight)/93);
    auto keysCharSize =    static_cast<int>((fieldWidth+fieldHeight)/70);
    auto message_x =       static_cast<double>((fieldWidth/4) - 20);
    auto message_y =       static_cast<double>((fieldHeight/2) - 20);
    auto keys_x =          static_cast<double>(fieldWidth/16);
    auto keys_y =          static_cast<double>(fieldHeight - 100);
    auto version_x =       static_cast<double>((fieldWidth/2) - 80);
    auto version_y =       static_cast<double>(fieldHeight - 30);
    auto image_x =         static_cast<double>((fieldWidth/4) + 60);
    auto image_y =         static_cast<double>(fieldHeight/10);
    
    sf::Texture texture;
    if(!texture.loadFromFile("splashGround.jpg"))
    {/*do nothing for now*/}
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(image_x,image_y);
    //draw sprite
    appWindow_->draw(sprite);
    
    //write message on screen
    sf::Font   font;
    //select font for our text
    if(!font.loadFromFile("Xanadu.ttf"))
    {/*do nothing for now*/}
    
    sf::Text   splashMessage;
    splashMessage.setFont(font);
    splashMessage.setCharacterSize(charSize);
    splashMessage.setPosition(message_x,message_y);
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
    playerKeys.setCharacterSize(keysCharSize);
    playerKeys.setPosition(keys_x,keys_y);
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
    version.setCharacterSize(versionCharSize);
    version.setPosition(version_x,version_y);
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
        //move segment by pixel to right each time we loop, that's too fast, the screen is too small.
        if(gameIsRunning_){
            if(segment_->onRightEdge()){
                //compute current coordinates
                auto[segX,segY] = segment_->getSegmentCoords();
                //move down one row
                segment_->moveSegment(segX,segY+1);
                //change direction
                segment_->setDirection(Direction::WEST);
                //get segment off the edge
                segment_->moveSegment(-1,0);
            }
            else if(segment_->onLeftEdge()){
                //compute current coordinates
                auto[segX,segY] = segment_->getSegmentCoords();
                //move down one row
                segment_->moveSegment(segX,segY+1);
                //change direction
                segment_->setDirection(Direction::EAST);
                //move segment by one unit to right
                segment_->moveSegment(1,0);//get it off the edge
            }
            else{//segment is on neither edge
                if(segment_->onRightEdge() || segment_->onLeftEdge()){
                    
                }
                //move segment in direction
                segment_->move(1,segment_->getDirection());
            }
        }
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