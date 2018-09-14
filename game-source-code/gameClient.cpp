#include "GameController.h"
#include <memory>
using std::make_shared;

int main()
{

    //create controller object
    //create a Game Controller object
    auto controller = make_shared<GameController>();
    //command controller to open application's window
    controller->openApplicationWindow();
    //command controller to display the splash_screen
    controller->displaySplashScreen();
    //command controller to run the game
    controller->playGame();
    
    //indicate that main terminated successfully
    return 0;
}