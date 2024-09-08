#include "PolygonSerialiser.h"
PolygonSerialiser::PolygonSerialiser(std::ofstream& file, Polygon* poly_) : poly(poly_) {
	save(file);
}

PolygonSerialiser::PolygonSerialiser(std::ifstream& file, Shape*& s) {
	download(file, s);
}

void PolygonSerialiser::save(std::ofstream& file) {
	shapeType type = polygon;
	file.write((const char*)&type, sizeof(shapeType));

	size_t size = poly->getPointsCounter();
	file.write((const char*)&size, sizeof(size));
	Point* coords = new Point[size];
	for (int i = 0; i < size; i++) {
		coords[i] = poly->operator[](i);
	}
	file.write((char*)coords, sizeof(Point) * size);

	size_t sideColorLength = strlen(poly->getSideColor());
	file.write((const char*)&sideColorLength, sizeof(sideColorLength));
	file.write(poly->getSideColor(), sideColorLength);

	size_t mainColorLength = strlen(poly->getMainColor());
	file.write((const char*)&mainColorLength, sizeof(mainColorLength));
	file.write(poly->getMainColor(), mainColorLength);

	unsigned id = poly->getId();
	file.write((const char*)&id, sizeof(id));
}

void PolygonSerialiser::download(std::ifstream& file, Shape*& s) {
	size_t numOfPoints;
	file.read((char*)&numOfPoints, sizeof(size_t));

	Point* points = new Point[numOfPoints];
	file.read((char*)points, sizeof(Point) * numOfPoints);
	size_t side;
	file.read((char*)&side, sizeof(side));
	char* sideC = new char[side + 1];
	file.read(sideC, side);

	size_t main;
	file.read((char*)&main, sizeof(main));
	char* mainC = new char[main + 1];
	file.read(mainC, main);
	unsigned id;
	file.read((char*)&id, sizeof(id));
	sideC[side] = '\0';
	mainC[main] = '\0';
	Shape* temp = new Polygon(points, numOfPoints, sideC, mainC, id);
	s = temp->clone();

	delete[] sideC;
	delete[] mainC;
}