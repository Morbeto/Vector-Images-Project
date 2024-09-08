#include "Vector.h"
Vector::Vector() {
	points = new Point[10];
};

Vector::Vector(const Vector& v) {
	copyFrom(v);
}

Vector& Vector::operator=(const Vector& v) {
	if (this != &v) {
		free();
		copyFrom(v);
	}
	return *this;
}

Vector::~Vector() {
	free();
}

size_t Vector::getCounter() const {
	return counter;
}
void Vector::addPoint(Point point) {
	if (counter == cap) {
		resize(2 * cap);
	}
	points[counter++] = point;
}
Point Vector::operator[](size_t index) {
	if (index < 0 || index >= counter) {
		throw "Invalid index.";
	}
	return points[index];
}
void Vector::copyFrom(const Vector& v) {
	points = new Point[v.cap];
	for (int i = 0; i < v.counter; i++) {
		points[i] = v.points[i];
	}
	cap = v.cap;
	counter = v.counter;
}

void Vector::resize(size_t newcap) {
	Point* temp = new Point[newcap];
	for (int i = 0; i < counter; i++) {
		temp[i] = points[i];
	}
	delete[] points;
	points = temp;
}

void Vector::free() {
	delete[] points;
}