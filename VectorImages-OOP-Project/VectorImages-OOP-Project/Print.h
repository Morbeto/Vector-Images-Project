#pragma once
#include"Command.h"
class Print : public Command{
public:
	Print(ShapeFactory*, const char* null);
	void execute()  override;
};

