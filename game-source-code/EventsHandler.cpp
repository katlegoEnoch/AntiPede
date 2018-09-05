//File_name: EventsHandler.cpp
//Author:    Stax The Engipreneur
//Date:      05 September 2018
//Details:   Definition of EventsHandler class member functions

#include "EventsHandler.h"

#include <iostream>
using namespace std;

shared_ptr<sf::Event> EventsHandler::extern_event_ = NULL;

EventsHandler::EventsHandler()
{
    sf::Event evnt;
    extern_event_ = make_shared<sf::Event>(evnt);
}

shared_ptr<sf::Event> EventsHandler::getEvent()
{
    return extern_event_;
}

sf::Event::EventType  EventsHandler::windowClosed() 
{
    return sf::Event::Closed;
}

sf::Event::EventType  EventsHandler::keyPressed() 
{
    return sf::Event::KeyPressed;
}
\

KeyCode EventsHandler::processEvent()
{
    if(extern_event_->type == windowClosed()){
        //close window
        return KeyCode::CLOSE_WINDOW;
    }
    
    else if(extern_event_->type == keyPressed()){
        switch(extern_event_->key.code){
            case sf::Keyboard::Escape:
                return KeyCode::CLOSE_WINDOW;
                cout << "Closing down" << endl;
                break;
            case sf::Keyboard::Space:
                //start game
                return KeyCode::START_GAME;
                break;
            case sf::Keyboard::Left:
                //move player left
                return KeyCode::MOVE_ANT_LEFT;
                break;
            case sf::Keyboard::Right:
                //move player right
                return KeyCode::MOVE_ANT_RIGHT;
                break;
            case sf::Keyboard::Up:
                //fire bullet from gun
                return KeyCode::FIRE_BULLET;
                break;
            default:
                return KeyCode::IGNORE;
                break;
        }//end switch
    }
}
