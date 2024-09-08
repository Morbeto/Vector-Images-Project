#pragma once
#include"ShapeSerialiser.h"
class PolygonSerialiser : public ShapeSerialiser
{private:
	Polygon* poly;
public:
	PolygonSerialiser(std::ofstream& file, Polygon* poly);
	PolygonSerialiser(std::ifstream& file, Shape*& s);

	void save(std::ofstream& file) override;
	void download(std::ifstream& file, Shape*& s) override;
};

