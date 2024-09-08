#pragma once
#include "ShapeFactory.h"
class Group :public  Shape , public ShapeFactory
{public:
	Group(Point* points, size_t counter, unsigned id);

	bool validateCoords(Shape* temp);

	void addShape(const Shape&);
	void addShape(Shape* temp);

	void print();
	shapeType getType() const override;
	Shape* clone() const override;
};

