#pragma once
#include<iostream>
#include"Point.h"

class Vector {
private:
	Point* points;
	size_t counter = 0;
	size_t cap = 10;
public:
	Vector();
	Vector(const Vector&);
	Vector& operator=(const Vector& v);
	~Vector();

	void addPoint(Point p);

	void print() {
		for (int i = 0; i < counter; i++) {
			std::cout << points[i];
		}
	}
	size_t getCounter() const;
	Point operator[](size_t index);
private:
	void copyFrom(const Vector&);
	void resize(size_t);
	void free();
};

