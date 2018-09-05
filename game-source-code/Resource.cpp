//File_name: Resource.cpp
//Author:    Stax The Engipreneur
//Date:      05 September 2018
//Details:   Definition of Resource members

#include "Resource.h"
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////
//type ClassName::static_data = NULL
shared_ptr<sf::Sprite> Resource::sprite_ = NULL;
shared_ptr<sf::Texture> Resource::texture_ = NULL;
shared_ptr<sf::Text>   Resource::mainText_ = NULL;
shared_ptr<sf::Text>   Resource::keysText_ = NULL;
shared_ptr<sf::Text>   Resource::versionText_ = NULL;
shared_ptr<sf::Font>   Resource::mainFont_ = NULL;
shared_ptr<sf::Font>   Resource::keysFont_ = NULL;
shared_ptr<sf::Font>   Resource::versionFont_ = NULL;    

void Resource::loadResourcesFromFiles()
{
    sf::Font mainFont;
    if(!mainFont.loadFromFile("Xanadu.ttf")){}
    else{mainFont_ = make_shared<sf::Font>(mainFont);}
    
    
    sf::Font keysFont;
    if(!keysFont.loadFromFile("Zanes.ttf")){}
    else{keysFont_ = make_shared<sf::Font>(keysFont);}

    sf::Font versionFont;
    if(!versionFont.loadFromFile("Serifa.ttf")){}
    else{versionFont_ = make_shared<sf::Font>(versionFont);}
    
    sf::Texture texture; 
    if(!texture.loadFromFile("SplashGround.jpg")){}
    else{texture_ = make_shared<sf::Texture>(texture);}
    
    sf::Text mainText;
    mainText_ = make_shared<sf::Text>(mainText);
    
    sf::Text keysText;
    keysText_ = make_shared<sf::Text>(keysText);
    
    sf::Text versionText;
    versionText_ = make_shared<sf::Text>(versionText);
    
    sf::Sprite sprite;
    sprite_ = make_shared<sf::Sprite>(sprite);
}

shared_ptr<sf::Texture> Resource::getTexture() 
{
    return texture_;
}
shared_ptr<sf::Font> Resource::getMainFont()  
{
    return mainFont_;
}

shared_ptr<sf::Font> Resource::getKeysFont()  
{
    return keysFont_;
}

shared_ptr<sf::Font> Resource::getVersionFont()  
{
    return versionFont_;
}

shared_ptr<sf::Sprite> Resource::getSprite()
{
    return Resource::sprite_;
}

shared_ptr<sf::Text> Resource::getMainText()  
{
    return mainText_;
}

shared_ptr<sf::Text> Resource::getKeysText()  
{
    return keysText_;
}

shared_ptr<sf::Text> Resource::getVersionText()  
{
    return versionText_;
}


