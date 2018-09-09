//Filename: EventsHandler.h
//Author:   Stax The Engipreneur
//Date:     05 September 2018
//Details:  Header file of object that handles events

#ifndef EVENTSHANDLER_H
#define EVENTSHANDLER_H

#include <SFML/Graphics.hpp>

#include <memory>
using std::shared_ptr;
using std::make_shared;

enum class KeyCode
{
    CLOSE_WINDOW,
    START_GAME,
    END_GAME,
    MOVE_ANT_LEFT,
    MOVE_ANT_RIGHT,
    FIRE_BULLET,
    IGNORE_INPUT
};

class EventsHandler{
    
public:
    EventsHandler();
    static shared_ptr<sf::Event> getEvent(); 
    sf::Event::EventType         keyPressed();
    sf::Event::EventType         windowClosed();
    KeyCode                      processEvent();

private:
    static shared_ptr<sf::Event> extern_event_;
};

#endif
