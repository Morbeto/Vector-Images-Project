#include "Help.h"
const char* commands[14] = {
	{"Open"},
	{"Print" },
	{"Create"},
	{"Group"},
	{"Ungroup"},
	{"Insert(in group)"},
	{"Extract(from group)"},
	{"Hide"},
	{"Unhide"},
	{"Translate"},
	{"Scale"},
	{"Save"},
	{"Save as"},
	{"Help"}
};
Help::Help() {
	execute();
};

void Help::execute() {
	std::cout << "Valid Commands\n";
	for (int i = 0; i < 14; i++) {
		std::cout << ">" << commands[i] << "\n";
	}
}