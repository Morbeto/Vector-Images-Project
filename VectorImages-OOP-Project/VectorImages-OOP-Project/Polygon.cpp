#include"Polygon.h"

Polygon::Polygon(Point* coords, size_t counter, const MyString& s, const MyString& m, unsigned id_) : Shape(coords, counter, s, m, id_) {};

Shape* Polygon::clone() const {
	return new Polygon(*this);
}

shapeType Polygon::getType() const {
	return polygon;
}

void Polygon::print() {
	std::cout << "polygon ";
	Shape::print();
}