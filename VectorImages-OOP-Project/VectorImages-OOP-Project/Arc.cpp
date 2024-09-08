#include"Arc.h"
#include<iostream>

Arc::Arc(unsigned radius_, short smallAngle_, short largeAngle_, Point* coords, size_t counter, const MyString& s, const MyString& m, unsigned id_) : Shape(coords, counter, s, m, id_) {
	setRadius(radius_);
	setSmallAngle(smallAngle_);
	setLargeAngle(largeAngle_);
}

void Arc::setRadius(unsigned radius_) {
	radius = radius_;
}

void Arc::setSmallAngle(short sAngle_) {
	if (sAngle_ < 0 || sAngle_ > 359) {
		throw "invalid data input";
	}
	smallAngle = sAngle_;
}

void Arc::setLargeAngle(short lAngle_) {
	if (lAngle_ < 0 || lAngle_ > 360) {
		throw "invalid data input";
	}
	largeAngle = lAngle_;
}

unsigned Arc::getRadius() const {
	return radius;
}

short Arc::getSmallAngle() const {
	return smallAngle;
}

short Arc::getLargeAngle() const {
	return largeAngle;
}

Shape* Arc::clone() const {
	return new Arc(*this);
}

shapeType Arc::getType() const {
	return arc;
}

void Arc::print() {
	std::cout << "arc " << radius << " " << smallAngle << " " << largeAngle;
	Shape::print();

}