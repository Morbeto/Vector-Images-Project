#pragma once
#include"Command.h"

class Translate : public Command
{public:
	Translate(ShapeFactory* fact, const char* fileInfo);

	void execute() override;

	void executeGroup(Group*&, unsigned vertical, unsigned horizontal);
};

