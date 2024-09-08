#pragma once
#include"Command.h"
class Hide : public Command{
public:
	Hide(ShapeFactory* f, const char* fileInfo);
	void execute() override;
};

