//File_name: CollisionDetector.cpp
//Author:    Stax The Engipreneur
//Date:      09 September 2018
//Details:   Definition of CollisionDetector members

#include "CollisionDetector.h"

void CollisionDetector::detectCollision(shared_ptr<Centipede> centipede,vector<Bullet>& bullets)
{
    //assign iterator to container for deletion
    vector<Segment>::iterator segIt = centipede->getBegin();
    //assign iterator to vector
    vector<Bullet>::iterator bul_it = begin(bullets);
    
     //for all the segments in the centipede
     for(size_t centLoc = 0; centLoc < centipede->numberOfSegments();centLoc++){
        //inner loop - for all the bullets
        for(size_t bulloc = 0; bulloc < bullets.size();bulloc++){
            //calculate size of region surrounding bullet
            auto bul_reg = bullets.at(bulloc).computeBulletRegion();
            //calculate region of region surrounding segment
            auto seg_reg = centipede->getSegmentAt(centLoc).computeSegmentRegion();
            //compute a mactch between the two regions, if there's a match
            if(!bullets.empty()){
                //compare the heights
                if(computeMatch(seg_reg,bul_reg)){
                    //if the heights also match
                    if(bullets.at(bulloc).getBulletHeight() == centipede->getSegmentAt(centLoc).getSegmentHeight()){
                        //change the current segment's state to false
                        centipede->getSegmentAt(centLoc).setSegmentState(false);
                        //delete segment from screen
                        centipede->destroySegmentAt(segIt);
                        // centipede_->getSegmentAt()
                        //change current bullet's state to false as well;
                        bullets.at(bulloc).setBulletState(true);
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
}


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

