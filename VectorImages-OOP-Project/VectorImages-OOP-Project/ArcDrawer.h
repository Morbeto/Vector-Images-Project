#pragma once
#include"ShapeDrawer.h"
class ArcDrawer : public ShapeDrawer
{private:
	Arc* arc;
public:
	ArcDrawer(Arc*, std::ofstream&);

	void draw(std::ofstream&) override;
};

