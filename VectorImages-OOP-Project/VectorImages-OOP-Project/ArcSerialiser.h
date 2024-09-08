#pragma once
#include"ShapeSerialiser.h"
class ArcSerialiser : ShapeSerialiser
{private:
	Arc* _arc;
public:
	ArcSerialiser(std::ofstream& file, Arc* arc);
	ArcSerialiser(std::ifstream& file, Shape*& temp);

	void save(std::ofstream& file) override;
	void download(std::ifstream& file,Shape*& s) override;

};

