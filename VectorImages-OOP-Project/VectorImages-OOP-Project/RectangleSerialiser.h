#pragma once
#include"ShapeSerialiser.h"
class RectangleSerialiser : public ShapeSerialiser
{private:
	 Rectangle* rect;
 public:
	 RectangleSerialiser(std::ofstream& file, Rectangle* rect);
	 RectangleSerialiser(std::ifstream& file, Shape*& shape);

	 void save(std::ofstream& file) override;
	 void download(std::ifstream& file, Shape*& shape) override;

};

