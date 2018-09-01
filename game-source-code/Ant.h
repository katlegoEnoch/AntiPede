//File_name: Ant.h
//Author:    Stax The Engipreneur
//Date:      31 August 2018
//Details:   Definition of Ant Model

/*An ant fires bullets at the centipede*/

#include <SFML/Graphics.hpp>

class Ant{
    
public:
    //instatiated with specific position on the field
    Ant(const int&, const int&);
    //clients of Ant object can...
    void drawAntOnField(sf::RenderWindow*);
    
private:
    //an ant has a position on the field
    int antX_;
    int antY_;

};