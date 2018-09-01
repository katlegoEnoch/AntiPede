//File_name: Segment.h
//Author:    Stax The Engipreneur
//Date:      31 August 2018
//Details:   

/*A centipede is made up of segments*/

class Segment{
public:
    //construct Segment object with specific location on field
    Segment(const int&, const int&);
    //clients of Segment can...
    void drawSegmentOnField(sf::RenderWindow* );
    
private:
    //has a coordinate on the field
    int segmentX_;
    int segmentY_;
    
};