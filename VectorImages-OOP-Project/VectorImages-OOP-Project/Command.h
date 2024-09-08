#pragma once
#include"Serialiser.h"
class Command 
{protected:
	ShapeFactory* fact = nullptr;
	MyString info;
public:
	Command() = default;
	Command(ShapeFactory* fact_, const char* fileInfo);
	virtual ~Command() {
		fact = nullptr;
	};

	void putInFile(const char* fileInfo);
	virtual void execute()  = 0;

};

