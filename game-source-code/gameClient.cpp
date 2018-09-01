#include "GameController.h"

int main()
{

    //create controller object
    //create a Game Controller object
    GameController controller;
    //command controller to open application's window
    controller.openApplicationWindow();
    //command controller to display the splash_screen
    controller.displaySplashScreen();
    //command controller to run the game
    controller.playGame();
    
    //indicate that main terminated successfully
    return 0;
}