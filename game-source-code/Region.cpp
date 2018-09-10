//Filename: Region.cpp
//Author:   Stax The Engipreneur
//Date:     09 September 2018
//Details:  Implementation of Region member functions

#include "Region.h"



Region::Region(const int& minValue, const int& maxValue, const int& center) : region_min_{minValue}, region_max_{maxValue}, centerX_{center}
{
    //data validation
    if(region_min_ < 0 || region_max_ > fieldWidth){
        throw RegionBeyondFieldBoundary{};
        
    }
    
}
