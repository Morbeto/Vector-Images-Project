#pragma once
#include"Command.h"
class Help : public Command
{public:
	Help();

	void execute() override;
};

