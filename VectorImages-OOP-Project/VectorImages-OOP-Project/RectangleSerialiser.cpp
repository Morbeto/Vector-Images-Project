#include "RectangleSerialiser.h"
RectangleSerialiser::RectangleSerialiser(std::ofstream& file, Rectangle* rectangle) : rect(rectangle) {
	save(file);
}

RectangleSerialiser::RectangleSerialiser(std::ifstream& file, Shape*& shape) {
	download(file, shape);
}

void RectangleSerialiser::save(std::ofstream& file) {
	shapeType temp = rectangle;

	int width = rect->getWidth();
	int height = rect->getHeight();
	file.write((const char*)&temp, sizeof(rectangle));
	file.write((const char*)&width, sizeof(int));
	file.write((const char*)&height, sizeof(int));

	size_t size = rect->getPointsCounter();
	file.write((const char*)&size, sizeof(size));
	Point* coords = new Point[size];
	for (int i = 0; i < size; i++) {
		coords[i] = rect->operator[](i);
	}
	file.write((char*)coords, sizeof(Point) * size);

	size_t sideColorLength = strlen(rect->getSideColor());
	file.write((const char*)&sideColorLength, sizeof(sideColorLength));
	file.write(rect->getSideColor(), sideColorLength);

	size_t mainColorLength = strlen(rect->getMainColor());
	file.write((const char*)&mainColorLength, sizeof(mainColorLength));
	file.write(rect->getMainColor(), mainColorLength);

	unsigned id = rect->getId();
	file.write((const char*)&id, sizeof(id));
}

void RectangleSerialiser::download(std::ifstream& file, Shape*& s) {
	int width = 0, height = 0;

	file.read((char*)&width, sizeof(int));
	file.read((char*)&height, sizeof(int));

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
	Shape* temp = new Rectangle(width, height, points, numOfPoints, sideC, mainC, id);
	s = temp->clone();

	delete[] sideC;
	delete[] mainC;
}