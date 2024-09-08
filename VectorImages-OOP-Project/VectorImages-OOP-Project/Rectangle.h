#pragma once
#include"Shape.h"

class Rectangle : public Shape {

private:
	int width, height;
public:
	Rectangle(int width, int height, Point* coords, size_t counter, const MyString& m, const MyString& s, unsigned id_);

	void setWidth(int);
	void setHeight(int);

	int getWidth() const;
	int getHeight() const;

	Shape* clone() const override;
	shapeType getType() const override;

	void print();
};