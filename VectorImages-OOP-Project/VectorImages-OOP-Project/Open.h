#pragma once
#include"Command.h"
class Open : public Command{
public:
	Open(ShapeFactory* fact, const char* fileInfo);

	void execute() override;
};

