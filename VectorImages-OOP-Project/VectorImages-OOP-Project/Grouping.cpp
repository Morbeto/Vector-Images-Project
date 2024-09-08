#include "Grouping.h"
Grouping::Grouping(ShapeFactory* fac, const char* fileInfo, unsigned id_) : Command(fac,fileInfo) , id(id_) {
	execute();
};

void Grouping::execute() {
	std::ifstream file("info.txt");
	if (!file) {
		std::cout << "Error!";
		return;
	}

	int x, y;
	Vector v;
	while (file >> x >> y) {
		Point p(x, y);
		v.addPoint(p);
	}
	Point* points = new Point[2];
	points[0] = v.operator[](0);
	points[1] = v.operator[](1);

	Group group(points, 2, id);

	fact->addShape(group);

	delete[] points;
	file.close();
};