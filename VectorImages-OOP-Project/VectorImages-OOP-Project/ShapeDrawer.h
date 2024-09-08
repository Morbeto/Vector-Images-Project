#pragma once
#include"Group.h"
#include<fstream>

class ShapeDrawer
{public:

	virtual void draw(std::ofstream& svgFile) = 0;
};

