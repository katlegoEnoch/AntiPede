//File_name: CollisionDetector.cpp
//Author:    Stax The Engipreneur
//Date:      09 September 2018
//Details:   Definition of CollisionDetector members

#include "CollisionDetector.h"

#include <iostream>
using namespace std;

bool CollisionDetector::computeMatch(shared_ptr<Region> segment,shared_ptr<Region> bullet)
{
    //extrac values from pointers passed in
    auto segRegionMax = segment->getRegionMax();
    auto segRegionMin = segment->getRegionMin();
    auto segCenter = segment->getCenter();
    auto bullRegionMax = bullet->getRegionMax();
    auto bullRegionMin = bullet->getRegionMin();
    auto bulCenter = bullet->getCenter();
    
    //radius for segment and center can be computed
    auto segRad = segRegionMax - segRegionMin;
    auto bulRad = bullRegionMax - bullRegionMin;    
    //compute degree of match
    //for bullet on left of segment
    
    if(bulCenter < segCenter){
        if((bulCenter+bulRad) < (segCenter-segRad)){
            return false;
        }//end if
        else
            return true;
    }// end if
    else if(bulCenter > segCenter){
        //for bullet to right of segment
        if((segCenter+bulRad) < (bulCenter-bulRad)){
            return false;
        }
        else
            return true;
    }// end else if
    //bullet on left or right of segment
    else if(((bulCenter+bulRad) >= (segCenter-segRad)) || ((bulCenter - bulRad) <= (segCenter+segRad)))
        return true;
    else
        return false;
    
}


bool CollisionDetector::detectCollision(vector<Segment>& centipede,vector<Bullet>& bullets)
{
    //assign iterator to container for deletion
    vector<Segment>::iterator segIt = begin(centipede);
    //assign iterator to vector
    vector<Bullet>::iterator bul_it = begin(bullets);
    //centipedes is a set of centipede objects i.e. a set of a set of segments
    bool sensed;
    
    //for all the segments in the centipede
    for(size_t centLoc = 0; centLoc < centipede.size();centLoc++){
        //inner loop - for all the bullets
        for(size_t bulloc = 0; bulloc < bullets.size();bulloc++){
            //calculate size of region surrounding bullet
            auto bul_reg = bullets.at(bulloc).computeBulletRegion();
            //calculate region of region surrounding segment
            auto seg_reg = centipede.at(centLoc).computeSegmentRegion();
            //compute a mactch between the two regions, if there's a match
            if(!bullets.empty()){
                //compare the heights
                if(computeMatch(seg_reg,bul_reg)){
                    //if the heights also match
                    if(bullets.at(bulloc).getBulletHeight() == centipede.at(centLoc).getSegmentHeight()){
                        //change the current segment's state to false
                        centipede.at(centLoc).setSegmentState(false);
                        //query the crown-state of the segment
                        splitCentipede(centipede,centLoc);//split the centipede at point of impact
                        //change current bullet's state to false as well;
                        bullets.at(bulloc).setBulletState(true);
                        sensed = true;
                        //we should also delete bullet from gun's memory
                        bullets.erase(bul_it);
                    }//end if
                    //compoute coordinates
                }//end if
            }//end if
            //increment iterator
            bul_it++;
        }//end inner loop
        //increment iterator
        segIt++;
    }//end outer for loop
     
    return sensed;
}


//splits Centipede and returns a set of pointers to smaller Centipede objects
void CollisionDetector::splitCentipede(vector<Segment>& centi,const size_t& split_loc)
{
    //ask segments at split location what its crown is
    auto crown = centi.at(split_loc).getSegmentCrown();
    cout << static_cast<int>(centi.at(split_loc).getSegmentCrown());
    //make decision based on segment's crown
    switch(crown){
        case Crown::HEAD:
            cout << "splitting head" << endl;
            //if it's a head, the element to its left becomes a head
            centi.at(split_loc-1).crownSegment(Crown::HEAD);
            break;
        case Crown::TAIL:
            cout << "splitting tail" << endl;
            //if it's a tail, the element to its right becomes a tail
            centi.at(split_loc+1).crownSegment(Crown::TAIL);
            break;
        case Crown::NEUTRAL:
            cout << "splitting body" << endl;
            //if it's neutral segments to its left becomes a head
            centi.at(split_loc-1).crownSegment(Crown::HEAD);
            //segment to right becomes tail
            centi.at(split_loc+1).crownSegment(Crown::TAIL);
            break;
        default:
            //segments are neutral by default
            centi.at(split_loc).crownSegment(Crown::NEUTRAL);
            break;
    }//end switch

}





