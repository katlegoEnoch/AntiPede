//File_name: ScreenSplasher.cpp
//Author:    Stax The Engipreneur
//Date:      04 September 2018
//Details:   Definition of ScreenSplasher's member functions

#include "ScreenSplasher.h"

ScreenSplasher::ScreenSplasher(shared_ptr<Window> appWindow,shared_ptr<Resource> resource) :
window_{appWindow},resource_{resource}
{}


void ScreenSplasher::displaySplashScreen()
{
    //clear window
    window_->getWindow()->clear();
    
    //call the private helpers
    resource_->loadResourcesFromFiles();
    
    //call private helper functions
    displayImage();
    printMainText();
    printKeysText();
    printVersionText();
    
    //display all 
    window_->getWindow()->display();
    //function done with its task, return control to caller
    return;
}

void ScreenSplasher::printMainText()
{
    auto charSize  = static_cast<int>((fieldWidth+fieldHeight)/47);
    auto message_x = static_cast<double>((fieldWidth/4) - 20);
    auto message_y = static_cast<double>((fieldHeight/2) - 20);
    
                    
    resource_->getMainText()->setFont(*(resource_->getMainFont()));
    resource_->getMainText()->setCharacterSize(charSize);
    resource_->getMainText()->setPosition(message_x,message_y);
    resource_->getMainText()->setFillColor(sf::Color::Green);
    resource_->getMainText()->setString("\tWelcome to AntIpede!\nPress Enter to start game");
    window_->getWindow()->draw(*(resource_->getMainText()));
}

void ScreenSplasher::printKeysText() 
{
    auto keysCharSize =    static_cast<int>((fieldWidth+fieldHeight)/70);
    auto keys_x =          static_cast<double>(fieldWidth/16);
    auto keys_y =          static_cast<double>(fieldHeight - 100);
    
    if(!resource_->getKeysFont()->loadFromFile("Zanes.ttf")){}
    else{
        resource_->getKeysText()->setFont(*(resource_->getKeysFont()));
        resource_->getKeysText()->setCharacterSize(keysCharSize);
        resource_->getKeysText()->setPosition(keys_x,keys_y);
        resource_->getKeysText()->setFillColor(sf::Color::Green);
        resource_->getKeysText()->setString("\tKEYS: left-arrow | move left\tright-arrow | move right\tSpace-Bar | fire bullet");
        window_->getWindow()->draw(*(resource_->getKeysText()));
    }
}


void ScreenSplasher::printVersionText()
{
    auto versionCharSize = static_cast<int>((fieldWidth+fieldHeight)/93);
    auto version_x =       static_cast<double>((fieldWidth/2) - 80);
    auto version_y =       static_cast<double>(fieldHeight - 30);

    if(!resource_->getVersionFont()->loadFromFile("Serifa.ttf")){}
    else{
        resource_->getVersionText()->setFont(*(resource_->getVersionFont()));
        resource_->getVersionText()->setCharacterSize(versionCharSize);
        resource_->getVersionText()->setPosition(version_x,version_y);
        resource_->getVersionText()->setFillColor(sf::Color::White);
        resource_->getVersionText()->setString("\tAntIpede v1.1");
        window_->getWindow()->draw(*(resource_->getVersionText()));
    }
}

void ScreenSplasher::displayImage() 
{
    auto image_x = static_cast<double>((fieldWidth/4) + 70);
    auto image_y = static_cast<double>((fieldHeight/10) +70);
    
    //load and display
     if(!resource_->getTexture()->loadFromFile("splashGround.jpg")){}
     else{
        resource_->getSprite()->setTexture(*(resource_->getTexture()));
        resource_->getSprite()->setPosition(image_x,image_y);
        window_->getWindow()->draw(*(resource_->getSprite()));
     }
}
