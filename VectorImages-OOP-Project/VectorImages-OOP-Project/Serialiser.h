#pragma once
#include"PolygonSerialiser.h"
#include"ArcSerialiser.h"
#include"SegmentSerialiser.h"
#include"RectangleSerialiser.h"
class Serialiser
{public:
	Serialiser(const char* file, ShapeFactory s);
	Serialiser(ShapeFactory& s, const char* fileInfo);

	void serialise(std::ofstream& file, ShapeFactory s);
	void deserialise(std::ifstream& file, ShapeFactory& S);

	void clearFile(const char* filePath);
};

