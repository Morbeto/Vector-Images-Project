#include "ArcSerialiser.h"
ArcSerialiser::ArcSerialiser(std::ofstream& file, Arc* arc_) : _arc(arc_) {
	save(file);
}

ArcSerialiser::ArcSerialiser(std::ifstream& file, Shape*& s) {
	download(file, s);
}

void ArcSerialiser::save(std::ofstream& file) {
	shapeType type = arc;
	unsigned rad = _arc->getRadius();
	short smallAngle = _arc->getSmallAngle();
	short largeAngle = _arc->getLargeAngle();

	file.write((const char*)&type, sizeof(shapeType));
	file.write((const char*)&rad, sizeof(unsigned));
	file.write((const char*)&smallAngle, sizeof(short));
	file.write((const char*)&largeAngle, sizeof(largeAngle));

	size_t size = _arc->getPointsCounter();
	file.write((const char*)&size, sizeof(size));
	Point* coords = new Point[size];
	for (int i = 0; i < size; i++) {
		coords[i] = _arc->operator[](i);
	}
	file.write((char*)coords, sizeof(Point) * size);

	size_t sideColorLength = strlen(_arc->getSideColor());
	file.write((const char*)&sideColorLength, sizeof(sideColorLength));
	file.write(_arc->getSideColor(), sideColorLength);

	size_t mainColorLength = strlen(_arc->getMainColor());
	file.write((const char*)&mainColorLength, sizeof(mainColorLength));
	file.write(_arc->getMainColor(), mainColorLength);

	unsigned id = _arc->getId();
	file.write((const char*)&id, sizeof(id));
}

void ArcSerialiser::download(std::ifstream& file, Shape*& s) {
	unsigned rad = 0;
	short smallAngle = 0;
	short largeAngle = 0;

	file.read((char*)&rad, sizeof(unsigned));
	file.read((char*)&smallAngle, sizeof(short));
	file.read((char*)&largeAngle, sizeof(short));

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
	Shape* temp = new Arc(rad, smallAngle, largeAngle, points, numOfPoints, sideC, mainC, id);
	s = temp->clone();

	delete[] sideC;
	delete[] mainC;
}

