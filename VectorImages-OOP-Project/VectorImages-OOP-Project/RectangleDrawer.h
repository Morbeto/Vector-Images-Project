#pragma once
#include"ShapeDrawer.h"
class RectangleDrawer : public ShapeDrawer
{private:
	Rectangle* temp;
public:
	RectangleDrawer(Rectangle*, std::ofstream& file);

	void draw(std::ofstream& file) override;

};

