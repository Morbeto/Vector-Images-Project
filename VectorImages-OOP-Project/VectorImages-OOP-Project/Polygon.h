#pragma once
#include"Shape.h"
#include<iostream>

class Polygon : public Shape {
public:
    Polygon(Point* coords, size_t counter, const MyString&, const MyString&, unsigned);


    Shape* clone() const override;
    shapeType getType() const override;

    void print();
};