//File_name: Renderer.cpp
//Author:    Stax The Engipreneur
//Date:      03 September 2018
//Details:   

#include "Renderer.h"

//constructor
Renderer::Renderer(shared_ptr<Window> window) : window_{window}
{}


void Renderer::drawField(const shared_ptr<Field> field)
{
    sf::RectangleShape rect;
    auto[boundX,boundY] = field->fieldBoundary();
    rect.setSize(sf::Vector2f(boundX,boundY));
    rect.setOutlineThickness(-10);
    rect.setFillColor(sf::Color(78,86,35));
    rect.setOutlineColor(sf::Color(70,50,30));
    
    window_->getWindow()->draw(rect);
    
    //return control to caller;
    return;
}

void Renderer::drawAntOnField(const shared_ptr<Ant> ant)
{
    sf::RectangleShape antShape;
    antShape.setSize(sf::Vector2f(ant->getAntSize(),ant->getAntSize()));
    auto[antX,antY] = ant->getAntCoords();
    antShape.setPosition(antX,antY);
    antShape.setFillColor(sf::Color::Green);
    
    window_->getWindow()->draw(antShape);
}

void Renderer::drawSegmentOnField(const Segment& seg,const Colour& col)
{
    //cout << "drawing segment" << endl; 
    //only draw live segments
    
    sf::CircleShape segment(seg.segmentSize());
    switch(col){
        case Colour::RED_:
            segment.setFillColor(RED);
            break;
        case Colour::YELLOW_:
            segment.setFillColor(YELLOW);
            break;
        default:
            segment.setFillColor(RED);
            break;
    }//end switch
    auto[segmentX,segmentY] = seg.getSegmentCoords();
    segment.setPosition(segmentX,segmentY);
    
    if(seg.segmentIsAlive()){
        //cout << "segment alive" << endl;
        window_->getWindow()->draw(segment);
    }
    else
       // cout << "segment destroyed" << endl;
    
    
    //return control to caller
    return;
}

void Renderer::drawCentipede(const shared_ptr<Centipede> centi)
{
    //initialize program variables
    size_t loc = 0;
    //command all segments to draw themselves
    for(; loc < centi->numberOfSegments()-1;loc++){
        //command centipede's render to draw current segment
        //Segment* seg_ptr = &centi->getSegmentAt(loc);
        drawSegmentOnField(centi->getSegmentAt(loc),Colour::RED_);
    }
    //for last element - head, draw a different colour
    drawSegmentOnField(centi->getSegmentAt(loc),Colour::YELLOW_);
}

void Renderer::drawCentipedes(const vector<shared_ptr<Centipede>> centis)
{
    //for all the centipedes in set
    for(size_t cent = 0; cent < centis.size();cent++){
        //command renderer to draw the current centipede
        drawCentipede(centis.at(cent)); 
        cout << "Rendering" << cent <<endl;
    }
}

void Renderer::drawGun(const shared_ptr<Gun> gun)
{
    sf::RectangleShape gunShape;
    gunShape.setSize(sf::Vector2f(10,10));
    auto[gunX,gunY] = gun->getGunCoords();
    gunShape.setPosition(gunX,gunY);
    gunShape.setFillColor(SILVER);
    
    window_->getWindow()->draw(gunShape);
}


void Renderer::drawBullets(const vector<Bullet> bullets)
{
    for(size_t loc = 0; loc < bullets.size(); loc++)
    {
       sf::CircleShape bulletShape(bullets.at(loc).getBulletSize());
       bulletShape.setFillColor(TURQUOISE);
       auto[bulX,bulY] = bullets.at(loc).getBulletCoords();
       bulletShape.setPosition(bulX,bulY);
        
       if(!bullets.at(loc).getBulletState()){
           window_->getWindow()->draw(bulletShape);
       } 
    }
        
    //return control to caller
    return;
}
