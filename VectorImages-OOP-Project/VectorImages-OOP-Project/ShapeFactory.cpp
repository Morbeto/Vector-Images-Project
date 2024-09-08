#include"ShapeFactory.h"
ShapeFactory::ShapeFactory() : shapes(new Shape* [10]), capacity(10) {};

ShapeFactory::ShapeFactory(const ShapeFactory& s) {
	copyFrom(s);
}

ShapeFactory& ShapeFactory::operator=(const ShapeFactory& s) {
	if (this != &s) {
		free();
		copyFrom(s);
	}
	return *this;
}

ShapeFactory::ShapeFactory(ShapeFactory&& s) noexcept {
	moveFrom(std::move(s));
}

ShapeFactory& ShapeFactory::operator=(ShapeFactory&& s) noexcept {
	if (this != &s) {
		free();
		moveFrom(std::move(s));
	}
	return *this;
}

ShapeFactory::~ShapeFactory() {
	free();
}

Shape*& ShapeFactory::getShape(size_t index) {
	if (index >= counter) {
		throw std::out_of_range("Index out of bounds");
	}
	return shapes[index];
}

size_t ShapeFactory::getCounter() const {
	return counter;
}

void ShapeFactory::addShape(Shape* shape) {
	if (counter == capacity) {
		resize(2 * capacity);
	}
	shapes[counter++] = shape->clone();
}

void ShapeFactory::addShape(const Shape& shape) {
	Shape* temp = shape.clone();
	addShape(temp);
}

void ShapeFactory::removeShape(unsigned id) {
	for (int i = 0; i < counter; i++) {
		if (shapes[i]->getId() == id) {
			for (int j = i; j < counter - 1; j++) {
				shapes[j] = shapes[j + 1]->clone();
			}
			counter--;
			return;
		}
	}
}

void ShapeFactory::printAll() {
	for (int i = 0; i < counter; i++) {
		if (shapes[i]->checkIfHidden() == false) {
			shapes[i]->print();
		}
	}
}

void ShapeFactory::copyFrom(const ShapeFactory& s) {
	shapes = new Shape * [s.capacity];
	capacity = s.capacity;
	counter = s.counter;
	for (int i = 0; i < counter; i++) {
		shapes[i] = s.shapes[i]->clone();
	}
}

void ShapeFactory::moveFrom(ShapeFactory&& s) {
	shapes = s.shapes;
	s.shapes = nullptr;

	counter = s.counter;
	capacity = s.capacity;
}

void ShapeFactory::resize(size_t cap) {
	Shape** temp = new Shape * [cap];
	for (int i = 0; i < counter; i++) {
		temp[i] = shapes[i]->clone();
	}
	for (int i = 0; i < counter; i++) {
		delete shapes[i];
	}
	shapes = temp;
	capacity = cap;
}

void ShapeFactory::free() {
	for (int i = 0; i < counter; i++) {
		delete shapes[i];
	}
	delete[] shapes;
}