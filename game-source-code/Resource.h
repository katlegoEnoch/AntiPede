//File_name: Resource.h
//Author:    Stax The Engipreneur
//Date:      04 September 2018
//Details:   Encapsulate SFML resources - texture, sprite, font and text inside Resource class

#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Graphics.hpp>

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;

class Resource{
    
public:
    //
    static void loadResourcesFromFiles();
    //accessors
    static shared_ptr<sf::Texture> getTexture();
    static shared_ptr<sf::Font>    getMainFont(); 
    static shared_ptr<sf::Font>    getKeysFont();
    static shared_ptr<sf::Font>    getVersionFont(); 
    static shared_ptr<sf::Sprite>  getSprite();  
    static shared_ptr<sf::Text>    getMainText();  
    static shared_ptr<sf::Text>    getKeysText();  
    static shared_ptr<sf::Text>    getVersionText();  
    

private:
    //resources encapsulated within Resource object
    static shared_ptr<sf::Texture> texture_;
    static shared_ptr<sf::Font>    mainFont_;
    static shared_ptr<sf::Font>    keysFont_;
    static shared_ptr<sf::Font>    versionFont_;
    static shared_ptr<sf::Sprite>  sprite_;
    static shared_ptr<sf::Text>    mainText_;
    static shared_ptr<sf::Text>    keysText_;
    static shared_ptr<sf::Text>    versionText_;    

};//end class definition

#endif