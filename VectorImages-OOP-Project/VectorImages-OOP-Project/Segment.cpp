#include "Segment.h"
Segment::Segment() : Shape() {};

Segment::Segment(Point* coords, size_t counter, const MyString& m, const MyString& s, unsigned id_) : Shape(coords, counter, m, s, id_) {
    double l = ((coords[0].getX() - coords[1].getX()) * (coords[0].getX() - coords[1].getX()) + (coords[0].getY() - coords[1].getY()) * (coords[0].getY() - coords[1].getY()));
    setLength(l);
}

void Segment::setLength(double l) {
    if (l >= 0) {
        length = l;
    }
}

double Segment::getLength() const {
    return length;
}

Shape* Segment::clone() const {
    return new Segment(*this);
}

shapeType Segment::getType() const {
    return segment;
}

void Segment::print() {
    std::cout << "segment ";
    Shape::print();
}