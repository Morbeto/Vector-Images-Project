#pragma once
#include"Command.h"
class Extract : public Command{
public:
	Extract(ShapeFactory* fact, const char* fileInfo);

	void execute() override;
};

