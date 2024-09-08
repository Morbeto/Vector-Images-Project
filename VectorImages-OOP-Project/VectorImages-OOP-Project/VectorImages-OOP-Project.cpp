// VectorImages-OOP-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"CommandPrompt.h"
int main() {
    MyString blueC("blue");
    MyString redC("red");
    Point* groupCoords = new Point[2]{ {10,10},{400,400} };
    Point* segPoints = new Point[2]{ {2,3},{60,60} };
    Point* polyPoints2 = new Point[3]{ {30,20},{50,90},{100,20} };
    Point* rectPoints = new Point[1]{ {10,60} };
    Point* arcPoints = new Point[1]{ {200,300} };
    Point* polyPoints = new Point[5]{ {100, 100}, {100,200}, {200,100} , {150,50},{100,20} };
    Point* rectPoints1 = new Point[1]{ {250,300} };
    Shape* segment1 = new Segment(segPoints, 2, blueC, redC, 13);
    Shape* rect1 = new Rectangle(12, 12, rectPoints, 1, "yellow", "orange", 12);
    Shape* arc1 = new Arc(50, 30, 90, arcPoints, 1, "pink", "purple", 11);
    Shape* poly1 = new Polygon(polyPoints, 5, "black", "white", 10);
    Shape* rect2 = new Rectangle(25, 25, rectPoints1, 1, "red", "orange", 9);
    Shape* arc2 = new Arc{ 50,5,360,arcPoints,1,"black","red",8 };
    Shape* triangle = new Polygon(polyPoints2, 3, "black", "brown", 7);

    Rectangle* bomba = new Rectangle(20, 20, rectPoints1, 1, "pink", "purple", 12);
    Shape* rect = bomba->clone();
    Rectangle* temp = (Rectangle*)rect;

    ShapeFactory fact;
    Group group(groupCoords, 2, 20);
    group.addShape(bomba);
    group.addShape(poly1);
    fact.addShape(arc1);
    fact.addShape(triangle);
    fact.addShape(segment1);
    fact.addShape(rect2);
    fact.addShape(group);
    ShapeFactory idk;
    Serialiser("shapes.dat", fact);

    CommandPrompt d;
    d.executeCommands();
}
