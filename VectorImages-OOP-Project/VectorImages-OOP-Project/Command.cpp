#include "Command.h"
Command::Command(ShapeFactory* fact_, const char* fileInfo) : fact(fact_) {
	putInFile(fileInfo);
}

void Command::putInFile(const char* fileInfo) {
	std::ofstream file("info.txt");
	if (!file) {
		std::cout << "Error occured while oppening file.\n";
		return;
	}
	file << fileInfo;
	file.close();
}
