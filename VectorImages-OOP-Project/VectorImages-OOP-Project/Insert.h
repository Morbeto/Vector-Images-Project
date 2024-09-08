#pragma once
#include"Command.h"
class Insert : public Command{
public:
	Insert(ShapeFactory*, const char* fileInfo);

	void execute() override;
};

