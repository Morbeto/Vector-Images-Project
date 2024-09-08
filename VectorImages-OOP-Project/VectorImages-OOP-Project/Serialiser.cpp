#include "Serialiser.h"
#include<fstream>
#include<iostream>
Serialiser::Serialiser(const char* filename, ShapeFactory s) {
	std::ofstream file(filename,std::ios::out);
	if (!file) {
		std::cout << "Error openning file\n";
		return;
	}
	serialise(file, s);
	file.close();
}

Serialiser::Serialiser( ShapeFactory& s,const char* filename) {
    std::ifstream file(filename, std::ios::in );
    if (!file) {
        std::cout << "Error openning file\n";
        return;
    }
    deserialise(file, s);
    file.close();
    clearFile(filename);
}

void Serialiser::serialise(std::ofstream& file, ShapeFactory s) {
	for (int i = 0; i < s.getCounter(); i++) {
        if (!s.getShape(i)->checkIfHidden()) {
            if (s.getShape(i)->getType() == segment) {
                SegmentSerialiser sd(file,(Segment*) s.getShape(i));
            }
            else if (s.getShape(i)->getType() == rectangle) {
                RectangleSerialiser rs(file,(Rectangle*) s.getShape(i));
            }
            else if (s.getShape(i)->getType() == arc) {
                ArcSerialiser as(file,(Arc*) s.getShape(i));
            }
            else if(s.getShape(i)->getType() == polygon) {
                PolygonSerialiser ps(file,(Polygon*) s.getShape(i));
            }
            else if (s.getShape(i)->getType() == group) {
                ShapeFactory* f = (Group*)s.getShape(i);
                serialise(file, *f);
            }
        }
	}
}

void Serialiser::deserialise(std::ifstream& file, ShapeFactory& factory) {
    while (file) {
        shapeType type;
        file.read((char*)(&type), sizeof(shapeType));

        if (file.fail()) {
            if (file.bad()) {
                std::cerr << "Critical error occurred during read operation!" << std::endl;
                break;
            }
            else {
                std::cout << "Succesufylly opened the file.\n";
                continue;
            }
        }

        Shape* shape = nullptr;

        switch (type) {
        case segment:
            SegmentSerialiser (file, shape);
            break;
        case rectangle:
            RectangleSerialiser (file, shape);
            break;
        case arc:
            ArcSerialiser (file, shape);
            break;
        case polygon:
            PolygonSerialiser (file, shape);
            break;
        default:
            continue;
        }
        if (shape) {
            factory.addShape(shape);
        }
        else {
        }
    }
}

void Serialiser::clearFile(const char* fileInfo) {
    std::ofstream clear(fileInfo, std::ios::trunc);
    if (!clear) {
        return;
    }
    clear.close();
}