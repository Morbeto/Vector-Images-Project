#include "Shape.h"
Shape::Shape() : mainC("none"), sideC("none"), coords(nullptr), id(0) {};

Shape::Shape(Point* coords_, size_t counter_, const MyString& s, const MyString& m, int id_) {
	coords = new Point[counter_];
	for (int i = 0; i < counter_; i++) {
		coords[i] = coords_[i];
	}
	coordsCounter = counter_;
	mainC = m;
	sideC = s;
	setId(id_);
}

Shape::Shape(const Shape& s) {
	copyFrom(s);
}

Shape& Shape::operator=(const Shape& s) {
	if (this != &s) {
		free();
		copyFrom(s);
	}
	return *this;
}

Shape::Shape(Shape&& s) noexcept {
	moveFrom(std::move(s));
}

Shape& Shape::operator=(Shape&& s) noexcept {
	if (this != &s) {
		free();
		moveFrom(std::move(s));
	}
	return *this;
}

Shape::~Shape() {
	free();
}

const char* Shape::getMainColor() const {
	return mainC.c_str();
}

const char* Shape::getSideColor() const {
	return sideC.c_str();
}

int Shape::getId() const {
	return id;
}

bool Shape::checkIfHidden() const {
	return hidden;
}
void Shape::setMainColor(const MyString& s) {
	mainC = s;

}

void Shape::setSideColor(const MyString& s) {
	sideC = s;
}

void Shape::setId(int id_) {
	id = id_;
}

void Shape::hide() {
	hidden = true;
}

void Shape::unhide() {
	hidden = false;
}

Point& Shape::operator[](size_t index) {
	if (index > coordsCounter || index < 0) {
		throw "Invalid index";
	}
	return coords[index];

}

void Shape::copyFrom(const Shape& s) {
	coords = new Point[s.coordsCounter];
	for (int i = 0; i < s.coordsCounter; i++) {
		coords[i] = s.coords[i];
	}
	coordsCounter = s.coordsCounter;
	mainC = s.mainC;
	sideC = s.sideC;
	id = s.id;
	hidden = s.hidden;

}

void Shape::moveFrom(Shape&& s) {
	coords = s.coords;
	s.coords = nullptr;

	mainC = s.mainC;
	sideC = s.sideC;

	coordsCounter = s.coordsCounter;
	id = s.id;
	hidden = s.hidden;
	s.coordsCounter = 0;
}

void Shape::free() {
	delete[] coords;
}

void Shape::print() {
	for (int i = 0; i < coordsCounter; i++) {
		std::cout << coords[i] << " ";
	}
	std::cout << sideC << " " << mainC << " ID " << id << std::endl;
}

size_t Shape::getPointsCounter() const {
	return coordsCounter;
}