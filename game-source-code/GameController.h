//Filename: GameController.h
//Author:   Stax The Engipreneur
//Date:     31 August 2018
//Details:  

#include "Field.h"
#include "Ant.h"
#include "Segment.h"

#include <SFML/Graphics.hpp>

class GameController{
    
public:
    GameController();
    //clients of GameController can...
    //run game loop
    void runGameLoop();
    
private:
    
    void openApplicationWindow();
    void writeSplashMessage();
    //query status of resource initialization

    //maintains all the game objects in its memory
    //Field*   field_;
    //Ant*     ant_;
    //Segment* segment_;
    //additional variables
    bool gameIsRunning_; //keeps record of game status
    
    sf::RenderWindow* appWindow_;
};