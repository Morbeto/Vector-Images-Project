#include "Hide.h"
#include "Hide.h"

Hide::Hide(ShapeFactory* factory, const char* fileInfo) : Command(factory, fileInfo) {
	execute();
}

void Hide::execute() {
	unsigned id = 0;
	std::ifstream file("info.txt");
	if (!file) {
		std::cout << "Error!";
		return;
	}
	else if (!(file >> id)) {
		throw "Invalid data thrown";
		return;
	}
	for (int i = 0; i < fact->getCounter(); i++) {
		if (id == fact->getShape(i)->getId()) {
			fact->getShape(i)->hide();
		}
	}
	file.close();

}