#include "Insert.h"

Insert::Insert(ShapeFactory* fact, const char* fileInfo) : Command(fact, fileInfo) {
	execute();
}

void Insert::execute() {
	std::ifstream file("info.txt");
	if (!file) {
		return;
	}

	unsigned grId, elemId;
	if (!(file >> grId >> elemId)) {
		return;
	}

	bool elemBool = false;
	bool grBool = false;
	unsigned loc = 0;
	unsigned eLoc = 0;
	for (int i = 0; i < fact->getCounter(); i++) {
		if (grId == fact->getShape(i)->getId() && fact->getShape(i)->getType() == group) {
			grBool = true;
			loc = i;
		}
		if (elemId == fact->getShape(i)->getId()) {
			elemBool = true;
			eLoc = i;
		}
	}
	if (grBool == true && elemBool == true) {
		Group* temp = (Group*)fact->getShape(loc);
		Shape* shape = fact->getShape(eLoc);

		if (temp->validateCoords(shape)) {
			temp->addShape(shape);
			fact->removeShape(elemId);

		}
		else {
			std::cout << "The shape was not in the diapazon of the group!\n";
		}
	}
	else {
		std::cout << "No group with that id was found.\n";
	}
	file.close();
}