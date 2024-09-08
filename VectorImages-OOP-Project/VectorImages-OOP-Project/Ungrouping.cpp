#include "Ungrouping.h"
Ungrouping::Ungrouping(ShapeFactory* fact, const char* fileInfo) : Command(fact,fileInfo) {
    execute();
}

void Ungrouping::execute() {
	std::ifstream file("info.txt");
	if (!file) {
		return;
	}
	bool caseFound = false;
	unsigned id;
	file >> id;

	for (size_t i = 0; i < fact->getCounter(); i++) {
		if (id == fact->getShape(i)->getId() && fact->getShape(i)->getType() == group) {
			caseFound = true;
			Group* group = (Group*)fact->getShape(i);
			for (int j = 0; j < group->getCounter(); j++) {
				fact->addShape(group->getShape(j));
			}
			break;
		}
	}
	if (caseFound) {
		fact->removeShape(id);
	}	
	file.close();

}