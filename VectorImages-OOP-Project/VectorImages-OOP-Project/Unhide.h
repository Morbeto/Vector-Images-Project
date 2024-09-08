#pragma once
#include"Command.h"
class Unhide : public Command{
public:
	Unhide(ShapeFactory*, const char* fileInfo);

	void execute() override;
};

