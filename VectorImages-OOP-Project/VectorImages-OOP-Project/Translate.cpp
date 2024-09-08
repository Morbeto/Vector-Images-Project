#include "Translate.h"
Translate::Translate(ShapeFactory* fact, const char* fileInfo) : Command(fact,fileInfo) {
	execute();
}

void Translate::execute() {
	std::ifstream file("info.txt");
	if (!file) {
		std::cout << "Error!";
		return;
	}

	unsigned id = 0;
	unsigned vertical = 0;
	unsigned horizontal = 0;
	if (!(file >> id >> vertical >> horizontal)) {
		throw "Invalid input of data detected.";
		return;
	}
	for (int i = 0; i < fact->getCounter(); i++) {
		if (id == fact->getShape(i)->getId() && fact->getShape(i)->getType() != group) {
			Shape* temp = fact->getShape(i)->clone();
			for (int j = 0; j < temp->getPointsCounter(); j++) {
				int x = temp->operator[](j).getX() + vertical;
				int y = temp->operator[](j).getY() + horizontal;

				temp->operator[](j).setX(x);
				temp->operator[](j).setY(y);
			}
			fact->getShape(i) = temp->clone();
			delete temp;
			file.close();
			return;
		}
		else if (id == fact->getShape(i)->getId() && fact->getShape(i)->getType() == group) {
			Group* group = (Group*)fact->getShape(i);
			executeGroup(group, vertical, horizontal);
		}
	}
	
}

void Translate::executeGroup(Group*& gr,unsigned vertical , unsigned horizontal) {
	for (size_t i = 0; i < gr->getCounter(); i++) {
		if (gr->getShape(i)->getType() != group) {
			Shape* temp = gr->getShape(i)->clone();
			for (int j = 0; j < temp->getPointsCounter(); j++) {
				int x = temp->operator[](j).getX() + vertical;
				int y = temp->operator[](j).getY() + horizontal;

				temp->operator[](j).setX(x);
				temp->operator[](j).setY(y);
			}
			gr->getShape(i) = temp->clone();
			delete temp;
		}
		else {
			Group* copy = (Group*)gr->getShape(i);
			executeGroup(copy,vertical,horizontal);
			gr->getShape(i) = copy;
		}
	}
}