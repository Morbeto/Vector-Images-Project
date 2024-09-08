#pragma once
#include"MyString.h"
#include"Vector.h"
enum shapeType {
	segment, rectangle, arc, polygon, group
};
class Shape
{
public:
	MyString mainC;
	MyString sideC;
	Point* coords;
	size_t coordsCounter = 0;
	unsigned id;
	bool hidden = false;
public:
	Shape();
	Shape(Point* coords, size_t counter, const MyString&, const MyString&, int);
	Shape(const Shape&);
	Shape& operator=(const Shape&);
	virtual ~Shape();

	Shape(Shape&& s) noexcept;
	Shape& operator=(Shape&& s) noexcept;

	const char* getMainColor() const;
	const char* getSideColor() const;
	int getId() const;
	Point& operator[](size_t index);
	size_t getPointsCounter() const;
	bool checkIfHidden() const;

	void setMainColor(const MyString& s);
	void setSideColor(const MyString& s);
	void setId(int);
	void hide();
	void unhide();

	virtual Shape* clone() const = 0;
	virtual shapeType getType() const = 0;

	virtual void print();
private:
	void copyFrom(const Shape& s);
	void moveFrom(Shape&&);
	void free();
};

