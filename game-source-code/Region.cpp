//Filename: Region.cpp
//Author:   Stax The Engipreneur
//Date:     09 September 2018
//Details:  Implementation of Region member functions

#include "Region.h"



Region::Region(const int& minValue, const int& maxValue) : region_min_{minValue}, region_max_{maxValue}
{
    //data validation
    if(region_min_ < 0 || region_max_ > fieldWidth){
        throw RegionBeyondFieldBoundary{};
        
    }
    
}
