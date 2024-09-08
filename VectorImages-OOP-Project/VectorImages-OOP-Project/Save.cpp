#include "Save.h"
Save::Save(ShapeFactory* fact, const char* fileInfo) : Command(fact, fileInfo) {
	execute();
}

void Save::execute() {
	std::ifstream file("info.txt");
	if (!file) {
		std::cout << "Error oppening file.\n";
		return;
	}
    char temp[1024];
	file >> temp;
	if (strcmp(temp, "as") == 0) {
		file.getline(temp, 1024);
		std::cout << temp;
		Drawer(temp,*fact);
	}
	else {
		Serialiser(temp, *fact);

	}
	file.close();
}