#pragma once
#include"ArcDrawer.h"
#include"SegmentDrawer.h"
#include"RectangleDrawer.h"
#include"PolygonDrawer.h"
class Drawer
{
public:
	Drawer(const char* filePath, ShapeFactory);

	void drawShapes(std::ofstream&, ShapeFactory);
};

