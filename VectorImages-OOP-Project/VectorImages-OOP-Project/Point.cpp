#include "Point.h"

Point::Point(int x_, int y_) {
	setX(x_);
	setY(y_);
}

void Point::setX(int x_) {
	x = x_;
}

void Point::setY(int y_) {
	y = y_;
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

std::ostream& operator<<(std::ostream& os, const Point p) {
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}