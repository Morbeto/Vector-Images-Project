#include "Print.h"

Print::Print(ShapeFactory* f, const char* null = " ") : Command(f, " null") {
	execute();
}

void Print::execute() {
	fact->printAll();
}