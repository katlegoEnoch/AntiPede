//Filename: Anti-pedeTests.cpp
//Author:   Stax The Engipreneur
//Date:     02 September 2018
//Details:  

#include "Field.h"
#include "Ant.h"
#include "Segment.h"


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

////////////////////FIELD INITIALIZATION TESTS///////////////////////////////////

TEST_CASE("Field with invalid boundaries cannot be initialized")
{
    CHECK_THROWS_AS(Field(fieldWidth+1,fieldHeight+1),FieldOutOfScreenBounds);
}

TEST_CASE("Field with valid boundaries is initiliazed correctly")
{
    auto testField = Field{fieldWidth-1, fieldHeight-1};
    auto[testX,testY] = testField.fieldBoundary();
    //compare against known values
    CHECK(testX == 799);
    CHECK(testY == 599);
}


////////////////ANT INITIALIZATION TESTS//////////////////////////
TEST_CASE("Ant with invalid y-coordinate cannot be created")
{
    //attempt to construct an ant with y-coordinates out of field bounds results in an exception being thrown
    CHECK_THROWS_AS(Ant(fieldWidth,fieldHeight+1,20),AntCoordinatesOutOfFieldBounds);
}

TEST_CASE("Ant with invalid x-coordinate cannot be created")
{
    //attemp to construct ant with invalid x coordinate results an in exception being thrown
    CHECK_THROWS_AS(Ant(fieldWidth+1,fieldHeight,20),AntCoordinatesOutOfFieldBounds);
}

//the size of the ant has to be realistic relative to the field dimensions. We impose limits on the size of ant that can be constructed
TEST_CASE("Ant with size beyond field dimensions cannot be created")
{
    //an example of an invalid ant is one 30% that of the field demensions
    auto invalid_ant_size = 0.3*fieldHeight;
    CHECK_THROWS_AS(Ant(fieldWidth,fieldHeight,invalid_ant_size),AntSizeBeyondFieldBounds);
}

TEST_CASE("Reasonably sized ant can be constructed successfully")
{
    auto valid_ant_size = 10.f;
    auto test_ant = Ant{fieldWidth,fieldHeight,valid_ant_size};
    auto[ant_x,ant_y] = test_ant.getAntCoords();
    //compare against known values and make assertions
    CHECK(ant_x == 800);
    CHECK(ant_y == 600);
    CHECK(test_ant.getAntSize() == 10.f);
}

/////Ant movement tests//////////////////////////////////////
TEST_CASE("Ant can be moved by one unit to the right if not at right edge")
{
    //create an ant object at random position on the field
    auto ant = Ant{fieldWidth/2,fieldHeight-30,10.f};
    //get ant coordinates before movement
    auto[antXB, antYB] = ant.getAntCoords();
    //move ant by one unit to the right
    ant.moveAnt(1,0);
    //get ant coords after operation
    auto[antXA,antYA] = ant.getAntCoords();
    //ant should have moved to right by one unit
    CHECK(antXA == antXB+1);
    //ant should be at same y position 
    CHECK(antYA== antYB);
}
TEST_CASE("Ant can be moved by one unit to the left")
{
    //create an ant object at random position on the field
    auto ant = Ant{fieldWidth/2,fieldHeight-30,10.f};
    //get ant coordinates before movement
    auto[antXB, antYB] = ant.getAntCoords();
    //move ant by one unit to the left
    ant.moveAnt(-1,0);
    //get ant coords after operation
    auto[antXA,antYA] = ant.getAntCoords();
    //ant should have moved to left by one unit
    CHECK(antXA == antXB-1);
    //ant should be at same y position 
    CHECK(antYA== antYB);
}
TEST_CASE("Ant cannot move beyond right boundary of field")
{
    //position an ant on the right boundary on the bottom row
    auto ant = Ant{fieldWidth-10,fieldHeight-30,10.f};
    //get coordinates of ant before movement operation
    auto[antXB,antYB] = ant.getAntCoords();
    //attempt to move the ant by 1 unit to the right
    ant.moveAnt(1,0);
    //get ant coordinates after move operation
    auto[antXA,antYA] = ant.getAntCoords();
    //ant coordinates should remain the same before and after operation i.e. ant cannot move beyond right edge
    CHECK(antXB == antXA);
    CHECK(antYB == antYA);
}
TEST_CASE("And cannot move beyond the left boundary of the field")
{
    //place an ant on the bottom row's left edge
    auto ant = Ant{10,fieldHeight-30,10.f};
    //get ant's coordinates before movement
    auto[antXB,antYB] = ant.getAntCoords();
    //attempt to move ant by one unit to the left
    ant.moveAnt(-1,0);
    //get ant coords after operation
    auto[antXA,antYA] = ant.getAntCoords();
    //ant's coordinates should be the same before and after attempted move operation
    CHECK(antXA == antXB);
    CHECK(antYA == antYB);
}

///////////////////////////////////SEGMENT-INITIALIZATION-TESTS////////////////////////////////////////////////////
TEST_CASE("Segment With invalid field coordinates cannot be constructed")
{
    CHECK_THROWS_AS(Segment(fieldWidth+1,fieldHeight+1,10),SegmentHasInvalidFieldCoordinates);
}

TEST_CASE("Segment with invalid x field coordinate cannot be constructed")
{
    CHECK_THROWS_AS(Segment(fieldWidth+1,fieldHeight,10),SegmentHasInvalidFieldCoordinates);
}
TEST_CASE("Segment with invalid y field coordinate cannot be constructed")
{
    CHECK_THROWS_AS(Segment(fieldWidth,fieldHeight+1,10),SegmentHasInvalidFieldCoordinates);
}

TEST_CASE("Segment with large radius cannot be constructed")
{
    auto invalid_segment_radius = 100;
    CHECK_THROWS_AS(Segment(fieldWidth,fieldHeight,invalid_segment_radius),SegmentRadiusBeyondFieldBounds);
}

////////////////////////////////////////SEGMENT MOVEMENT TESTS/////////////////////////////////////
TEST_CASE("Segment can be moved by one unit to right if not positioned on right edge")
{
    //place segment at any location but right edge
    auto segment = Segment{30,30,10.f};
    //get coordinates of segment before movement
    auto[segXB,segYB] = segment.getSegmentCoords();
    //move segment by one unit to the right
    segment.moveSegment(1,0);
    //get coordinats of segment after movement operation
    auto[segXA,segYA] = segment.getSegmentCoords();
    //x should have changed by one unit
    CHECK(segXA == segXB+1);
    //y should be the same
    CHECK(segYA == segYB);
}

TEST_CASE("Segment can be moved by one unit to left if not positioned on left edge")
{
    //place segment at any location but right edge
    auto segment = Segment{50,50,10.f};
    //get coordinates of segment before movement
    auto[segXB,segYB] = segment.getSegmentCoords();
    //move segment by one unit to the right
    segment.moveSegment(-1,0);
    //get coordinats of segment after movement operation
    auto[segXA,segYA] = segment.getSegmentCoords();
    //x should have changed by one unit
    CHECK(segXA == segXB-1);
    //y should be the same
    CHECK(segYA == segYB);

    
}

TEST_CASE("Segment cannot move beyond right edge")
{
    //position a segment on the top row right edge
    auto segment = Segment{fieldWidth-10,30, 10.f};
    //get segment coordinates before movement operation
    auto[segXB,segYB] = segment.getSegmentCoords();
    //attempt to move segment by one unit beyond right edge
    segment.moveSegment(1,0);
    //get coordinates of segment after movement
    auto[segXA,segYA] = segment.getSegmentCoords();
    //x coordinate should not have changed
    CHECK(segXA == segXB);
    CHECK_FALSE(segYA == segYB);
}

TEST_CASE("Segment cannot move beyond left edge")
{
    //position a segment on the top row left edge
    auto segment = Segment{10,30, 10.f};
    //get segment coordinates before movement operation
    auto[segXB,segYB] = segment.getSegmentCoords();
    //attempt to move segment by one unit beyond left edge
    segment.moveSegment(-1,0);
    //get coordinates of segment after movement
    auto[segXA,segYA] = segment.getSegmentCoords();
    //x coordinate should not have changed
    CHECK(segXA == segXB);
    CHECK_FALSE(segYA == segYB);
}

TEST_CASE("Segment moves down by one row when moving from right edge")
{
    //position a segment on the top row right edge
    auto segment = Segment{fieldWidth-10,30, 10.f};
    //get segment coordinates before movement operation
    auto[segXB,segYB] = segment.getSegmentCoords();
    //attempt to move segment by one unit beyond right edge
    segment.moveSegment(1,0);
    //get coordinates of segment after movement
    auto[segXA,segYA] = segment.getSegmentCoords();
    //x coordinate should not have changed
    CHECK(segXA == segXB);
    //segment should move down by one row
    CHECK(segYA == segYB+1);
}

TEST_CASE("Segment moves down by one row when moving from edge")
{
    //position a segment on the top row left edge
    auto segment = Segment{10,30, 10.f};
    //get segment coordinates before movement operation
    auto[segXB,segYB] = segment.getSegmentCoords();
    //attempt to move segment by one unit beyond left edge
    segment.moveSegment(-1,0);
    //get coordinates of segment after movement
    auto[segXA,segYA] = segment.getSegmentCoords();
    //x coordinate should not have changed
    CHECK(segXA == segXB);
    //segment should move down by one row
    CHECK(segYA == segYB+1);
}


