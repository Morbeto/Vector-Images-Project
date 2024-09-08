#pragma once
#include"Command.h"
class Create : public Command
{private:
	unsigned id;
public:
	Create(ShapeFactory*, const char*, unsigned id);

	size_t countSpaces(const char* fileInfo);

	void execute() override;
};

