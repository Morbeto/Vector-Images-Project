#include "Group.h"
#include<cmath>
Group::Group(Point* points, size_t num, unsigned id) : Shape(points, num, "none", "none", id) {};

bool Group::validateCoords(Shape* shape) {
    int minX, maxX, minY, maxY;
    int x1 = this->operator[](0).getX();
    int x2 = this->operator[](1).getX();
    int y1 = this->operator[](0).getY();
    int y2 = this->operator[](1).getY();

    minX = std::min(x1, x2);
    maxX = std::max(x1, x2);
    minY = std::min(y1, y2);
    maxY = std::max(y1, y2);

    shapeType type = shape->getType();
    if (type == polygon || type == segment || type == group) {
        for (int i = 0; i < shape->getPointsCounter(); i++) {
            int x = shape->operator[](i).getX();
            int y = shape->operator[](i).getY();

            if (x < minX || x > maxX || y < minY || y > maxY) {
                return false;
            }
        }
    }
    else if (type == rectangle) {
        Rectangle* temp = (Rectangle*)shape;
        int x = shape->operator[](0).getX();
        int y = shape->operator[](0).getY();
        int width = temp->getWidth();
        int height = temp->getHeight();

        int x2 = x + width;
        int y2 = y + height;

        if (x < minX || x2 > maxX || y < minY || y2 > maxY) {
            return false;
        }
    }
    else if (type == arc) {
        Arc* temp = (Arc*)shape;

        int centerX = shape->operator[](0).getX();
        int centerY = shape->operator[](0).getY();
        int radius = temp->getRadius();

        if (centerX - radius < minX || centerX + radius > maxX ||
            centerY - radius < minY || centerY + radius > maxY) {
            return false;
        }
    }
    return true;
}

void Group::addShape(const Shape& s) {
    Shape* temp = s.clone();
    ShapeFactory::addShape(temp);
}

void Group::addShape( Shape* s) {
    if (validateCoords(s)) {
        ShapeFactory::addShape(s);
    }
}

void Group::print() {
    std::cout << "Shapes in the group with id:" << getId() << '\n';
    ShapeFactory::printAll();
    std::cout << "-----------------------------------------\n";
}

shapeType Group::getType() const {
    return group;
}

Shape* Group::clone() const {
    return new Group(*this);
}


