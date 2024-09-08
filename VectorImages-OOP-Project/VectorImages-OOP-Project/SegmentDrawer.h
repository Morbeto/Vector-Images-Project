#pragma once
#include"ShapeDrawer.h"
class SegmentDrawer : public ShapeDrawer{
private:
	Segment* temp;
public:
	SegmentDrawer( Segment* , std::ofstream&);

	void draw(std::ofstream& svgFile) override;

};

