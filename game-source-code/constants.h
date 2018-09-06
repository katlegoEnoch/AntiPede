//Filename: constants.h
//Author:   Stax The Engipreneur
//Date:     02 September 2018
//Details:  Constants that will be used throughout the program

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics.hpp>

#define fieldWidth  800                                                                                                            
#define fieldHeight 600

#define M_GREEN sf::Color(75,83,32)
#define RED sf::Color(255, 0, 0) 
#define BLUE sf::Color(0, 0, 255)
#define GREEN sf::Color(0, 255, 0)
#define YELLOW sf::Color(255, 255, 0)
#define TURQUOISE sf::Color(0, 255, 255)
#define VIOLET sf::Color(255, 0, 255)
#define BLACK sf::Color(0, 0, 0)
#define WHITE sf::Color(255, 255, 255)
#define SILVER sf::Color(130, 170, 190)
#define GREY sf::Color(65, 85, 95)

enum class Colour{M_GREEN_,RED_,BLUE_,GREEN_,YELLOW_,TURQUOISE_,VIOLET_,BLACK_,WHITE_,SILVER_,GREY_};

enum class Direction{NORTH, EAST, SOUTH, WEST};

#endif