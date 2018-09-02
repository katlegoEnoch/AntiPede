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

//////////////////////////////////////////////////////////////


