#include "SegmentSerialiser.h"
SegmentSerialiser::SegmentSerialiser(std::ofstream& file, Segment* s) : seg(s) {
	save(file);

};
SegmentSerialiser::SegmentSerialiser(std::ifstream& file, Shape*& s) {
	download(file,s);

};

void SegmentSerialiser::save(std::ofstream& file) {
	shapeType type = segment;
	file.write((const char*)&type, sizeof(shapeType));

	size_t size = seg->getPointsCounter();
	file.write((const char*)&size, sizeof(size));
	Point* coords = new Point[size];
	for (int i = 0; i < size; i++) {
		coords[i] = seg->operator[](i);
	}
	file.write((char*)coords, sizeof(Point) * size);

	size_t sideColorLength = strlen(seg->getSideColor());
	file.write((const char*)&sideColorLength, sizeof(sideColorLength));
	file.write(seg->getSideColor(), sideColorLength);

	size_t mainColorLength = strlen(seg->getMainColor());
	file.write((const char*)&mainColorLength, sizeof(mainColorLength));
	file.write(seg->getMainColor(), mainColorLength);

	unsigned id = seg->getId();
	file.write((const char*)&id, sizeof(id));

};
void SegmentSerialiser::download(std::ifstream& file,Shape*& s)  {

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
	Shape* temp = new Segment(points, numOfPoints, sideC, mainC, id);
	s = temp->clone();
	delete[] sideC;
	delete[] mainC;
};