#include "GameController.h"

int main()
{
    //create controller object
    //when a controller object is created, window is opened and a message is displayed on the screen
    GameController controller;
    //run the game loop via the controller
    controller.runGameLoop();
    
    //indicate that main terminated successfully
    return 0;
}