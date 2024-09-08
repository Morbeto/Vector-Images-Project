#include "Create.h"

const char* colors[] = {
	"red", "green", "orange", "blue", "purple", "brown", "black", "white", "cyan", "magenta", "yellow","pink"
};

const size_t numColors = sizeof(colors) / sizeof(colors[0]);

bool isValidColor(const MyString& color) {
	const char* colorStr = color.c_str();
	for (size_t i = 0; i < numColors; ++i) {
		if (strcmp(colorStr, colors[i]) == 0) {
			return true;
		}
	}

	return false;
}
Create::Create(ShapeFactory* f, const char* shapeInfo, unsigned id_) : Command(f, shapeInfo), id(id_) {
	execute();
}



size_t Create::countSpaces(const char* fileInfo) {
	std::ifstream file(fileInfo);

	if (!file.is_open()) {
		std::cerr << "Error: Unable to open file " << fileInfo << std::endl;
		return -1;
	}

	size_t count = 0;
	char temp[1000];
	while (file >> temp) {
		count++;
	}
	file.close();
	return count;
}

void Create::execute() {

	std::ifstream file("info.txt");
	if (!file) {
		std::cout << "Error!";
		return;
	}
	char shapeType[28];

	file >> shapeType;
	if (!strcmp(shapeType, "segment")) {
		int x1, y1, x2, y2;
		MyString sideColor, mainColor;

		if (!(file >> x1 >> y1 >> x2 >> y2 >> sideColor >> mainColor)) {
			throw "Invalid input of data detected.";
		}
		else {
			if (!isValidColor(sideColor) || !isValidColor(mainColor)) {
				throw "Invalid color thrown";
			}
			Point* segPoints = new Point[2]{ {x1,y1},{x2,y2} };
			Segment temp(segPoints, 2, sideColor, mainColor, id);
			fact->addShape(temp);

			delete[] segPoints;
		}
	}
	else if (!strcmp(shapeType, "rectangle")) {
		int x1, y1, width, height;
		MyString sideColor, mainColor;

		if (!(file >> x1 >> y1 >> width >> height >> sideColor >> mainColor)) {
			throw "Invalid input of data detected.";
		}

		else {
			if (!isValidColor(sideColor) || !isValidColor(mainColor)) {
				throw "Invalid color thrown";
			}

			Point* recPoint = new Point[1]{ {x1,y1} };
			Rectangle temp(width, height, recPoint, 1, sideColor, mainColor, id);
			fact->addShape(temp);

			delete[] recPoint;
		}
	}
	else if (!strcmp(shapeType, "arc")) {
		int x1, y1;
		unsigned radius; short smallAngle, largeAngle;
		MyString sideC, mainC;
		if (!(file >> x1 >> y1 >> radius >> smallAngle >> largeAngle >> sideC >> mainC)) {
			throw "invalid input of data detected.";
		}
		if (!isValidColor(sideC) || !isValidColor(mainC)) {
			throw "Invalid color thrown";
		}
		Point* point = new Point[1]{ {x1,y1} };
		Arc temp(radius, smallAngle, largeAngle, point, 1, sideC, mainC, id);
		fact->addShape(temp);

		delete[] point;
	}
	else if (!strcmp(shapeType, "polygon")) {
		Vector v;
		int x, y;
		MyString sideC, mainC;

		size_t count = countSpaces("info.txt");
		count -= 3;
		count /= 2;

		while (count > 0) {
			file >> x >> y;
			Point point(x, y);
			v.addPoint(point);
			count--;
		}
		file >> sideC >> mainC;
		std::cout << sideC.c_str() << " " << mainC.c_str() << "\n";

		Point* temp = new Point[v.getCounter()];
		for (int i = 0; i < v.getCounter(); i++) {
			temp[i] = v.operator[](i);
		}
		if (!isValidColor(sideC) || !isValidColor(mainC)) {
			throw "Invalid color thrown";
		}
		Polygon poly(temp, v.getCounter(), sideC, mainC, id);
		fact->addShape(poly);

		delete[] temp;
	}
	else {
		std::cout << "Invalid shape thrown.\n";
		return;
	}

}


