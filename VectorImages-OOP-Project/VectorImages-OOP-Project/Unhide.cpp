#include "Unhide.h"
Unhide::Unhide(ShapeFactory* fact, const char* fileInfo) : Command(fact, fileInfo) {
	execute();
}

void Unhide::execute() {
	unsigned id = 0;

	std::ifstream file("info.txt");
	if (!file) {
		std::cout << "Error!";
		return;
	}
	else if (!(file >> id)) {
		throw "invalid data thrown";
		file.close();
	}
	for (int i = 0; i < fact->getCounter(); i++) {
		if (id == fact->getShape(i)->getId()) {
			fact->getShape(i)->unhide();
		}
	}
	file.close();
}