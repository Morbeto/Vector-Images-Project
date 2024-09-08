#pragma once 
#include<iostream>

struct Point {
private:
	int x, y;
public:
	Point(int = 0, int = 0);

	void setX(int);
	void setY(int);

	int getX() const;
	int getY() const;

	friend std::ostream& operator<<(std::ostream& os, const Point p);
};

