#pragma once
#include"Command.h"
class Save : public Command
{public:
	Save(ShapeFactory* fact, const char* fileInfo);

	void execute();
};

