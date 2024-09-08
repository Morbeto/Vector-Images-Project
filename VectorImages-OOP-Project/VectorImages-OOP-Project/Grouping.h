#pragma once
#include"Command.h"

class Grouping: public Command{
private:
	unsigned id;
public:
	Grouping(ShapeFactory*, const char* , unsigned id);

	void execute() override;
};

