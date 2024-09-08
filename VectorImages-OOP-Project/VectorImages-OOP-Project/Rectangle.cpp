#include"Rectangle.h"
#include<iostream>

Rectangle::Rectangle(int width, int height, Point* coords, size_t counter, const MyString& m, const MyString& s, unsigned id_) : Shape(coords, counter, m, s, id_) {
    setWidth(width);
    setHeight(height);
};

void Rectangle::setWidth(int width_) {
    if (width_ > 0) {
        width = width_;
    }
    else {
        throw "Invalid data thrown.";
    }
}

void Rectangle::setHeight(int height_) {
    if (height_ > 0) {
        height = height_;
    }
    else {
        throw "invalid data thrown.";
    }
}

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

Shape* Rectangle::clone() const {
    return new Rectangle(*this);
}

shapeType Rectangle::getType() const {
    return rectangle;
}

void Rectangle::print() {
    std::cout << "rectangle " << width << " " << height << " ";
    Shape::print();
}