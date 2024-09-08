#include "Extract.h"

Extract::Extract(ShapeFactory* fact_, const char* fileInfo) : Command(fact_, fileInfo) {
	execute();
}

void Extract::execute() {
	bool groupFinder = false;
	size_t groupAllocator = 0;
	unsigned grId, elemId;
	std::ifstream file("info.txt");

	if (!file || !(file >> grId >> elemId)) {
		return;
	}
	for (size_t i = 0; i < fact->getCounter(); i++) {
		if (grId == fact->getShape(i)->getId() && fact->getShape(i) != nullptr) {
			groupFinder = true;
			groupAllocator = i;
		}
	}
	if (!groupFinder) {
		file.close();
		return;
	}
	Group* temp = (Group*)fact->getShape(groupAllocator);
	for (size_t i = 0; i < fact->getCounter(); i++) {
		if (elemId == temp->getShape(i)->getId()) {
			Shape* shape = temp->getShape(i);
			fact->addShape(shape);
			temp->removeShape(elemId);
			file.close();
			return;
		}
	}
	file.close();
}