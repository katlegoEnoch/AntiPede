//File_name: EventsHandler.cpp
//Author:    Stax The Engipreneur
//Date:      05 September 2018
//Details:   Definition of EventsHandler class member functions

#include "EventsHandler.h"

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
    KeyCode code;
    
    if(extern_event_->type == windowClosed()){
        //close window
        //code = KeyCode::CLOSE_WINDOW;
        code = KeyCode::END_GAME;
    }
    
    else if(extern_event_->type == keyPressed()){
        switch(extern_event_->key.code){
            case sf::Keyboard::Escape:
                code = KeyCode::END_GAME;
                break;
            case sf::Keyboard::Enter:
                //start game
                code =  KeyCode::START_GAME;
                break;
            case sf::Keyboard::Left:
                //move player left
                code = KeyCode::MOVE_ANT_LEFT;
                break;
            case sf::Keyboard::Right:
                //move player right
                code = KeyCode::MOVE_ANT_RIGHT;
                break;
            case sf::Keyboard::Space:
                //fire bullet from gun
                code = KeyCode::FIRE_BULLET;
                break;
            default:
                code = KeyCode::IGNORE;
                break;
        }//end switch
    }
    return code;
}
