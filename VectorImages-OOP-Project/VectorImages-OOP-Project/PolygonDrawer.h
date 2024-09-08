#pragma once
#include"ShapeDrawer.h"
class PolygonDrawer : public ShapeDrawer
{private:
	Polygon* poly;
public:
	PolygonDrawer(Polygon* poly, std::ofstream& file);

	void draw(std::ofstream&);
};

