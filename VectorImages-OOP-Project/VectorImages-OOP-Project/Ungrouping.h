#pragma once
#include"Command.h"
class Ungrouping : public Command{
private:
public:
	Ungrouping(ShapeFactory* fact, const char* fileinfo);

	void execute() override;
};

