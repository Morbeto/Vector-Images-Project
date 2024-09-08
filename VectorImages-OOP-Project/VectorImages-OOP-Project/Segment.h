#pragma once
#include"Shape.h"
class Segment : public Shape
{
private:
	double length;
public:
	Segment();
	Segment(Point* coords, size_t counter, const MyString&, const MyString&, unsigned);

	void setLength(double);
	double getLength() const;

	Shape* clone() const override;
	shapeType getType() const override;

	void print();
};

