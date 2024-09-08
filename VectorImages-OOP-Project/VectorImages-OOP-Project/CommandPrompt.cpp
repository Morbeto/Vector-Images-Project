#include "CommandPrompt.h"
CommandPrompt::CommandPrompt()  {
};


CommandPrompt::~CommandPrompt() {
	inputId();
}

void CommandPrompt::executeCommands() {
	while (true) {
		char command[128];
		char idk[1000];
		std::cout << "-----------------\nEnter a command - ";
		std::cin.getline(command, 128);
		std::cout << "-----------------\n";
		inputData(command);
		std::ifstream file("data.txt");
		if (!file) {
			return;
		}
		file >> command;
		file.getline(idk, 1000);

		try {
			if (!strcmp(command, "quit") || !strcmp(command, "exit")) {
				break;
			}
			else if (!strcmp(command, "open")) {
				Open(&factory, idk);
			}
			else if (!strcmp(command, "create")) {
				Create(&factory, idk, idCounter++);
			}
			else if (!strcmp(command, "print")) {
				Print(&factory, " ");
			}
			else if (!strcmp(command, "group")) {
				Grouping(&factory, idk, idCounter++);
			}
			else if (!strcmp(command, "ungroup")) {
				Ungrouping(&factory, idk);
			}
			else if (!strcmp(command, "insert")) {
				Insert(&factory, idk);
			}
			else if (!strcmp(command, "extract")) {
				Extract(&factory, idk);
			}
			else if (!strcmp(command, "hide")) {
				Hide(&factory, idk);
			}
			else if (!strcmp(command, "show")) {
				Unhide(&factory, idk);
			}
			else if (!strcmp(command, "translate")) {
				Translate(&factory, idk);
			}
			else if (!strcmp(command, "save")) {
				Save(&factory, idk);
			}
			else if (!strcmp(command, "help")) {
				Help();
			}
			else {
				std::cout << "Invalid command\n";

			}
		}
		catch (const char* error) {
			std::cout << "Invalid parameters.\n";
		}

	}
}

void CommandPrompt::retrieveFromFile() {
	std::ifstream idFile("idFile.txt");
	if (!idFile) {
		std::cout << "Error!";
		return;
	}
	idFile >> idCounter;
}

unsigned CommandPrompt::retrieveCurrentID() {

	return idCounter;
}

void CommandPrompt::inputId() {
	std::ofstream idFile("idFile.txt");
	if (!idFile) {
		std::cout << "Error!";
		return;
	}
	idFile << idCounter;
	idFile.close();
}

void CommandPrompt::inputData(const char* info) {
	std::ofstream file("data.txt");
	if (!file) {
		std::cout << "Error!";
		return;
	}
	file << info;
	file.close();
}