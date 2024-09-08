#pragma once
#include"Shape.h"
class Arc : public Shape {
private:
	unsigned radius;
	short smallAngle, largeAngle;
public:
	Arc(unsigned, short, short, Point* coords, size_t counter, const MyString&, const MyString&, unsigned);

	void setRadius(unsigned);
	void setSmallAngle(short);
	void setLargeAngle(short);

	unsigned getRadius() const;
	short getSmallAngle() const;
	short getLargeAngle() const;

	Shape* clone() const override;
	shapeType getType() const override;

	void print();
};