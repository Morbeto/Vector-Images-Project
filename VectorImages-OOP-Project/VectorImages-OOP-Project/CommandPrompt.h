#pragma once
#include"Help.h"
#include"Open.h"
#include"Create.h"
#include"Print.h"
#include"Grouping.h"
#include"Ungrouping.h"
#include"Extract.h"
#include"Insert.h"
#include"Hide.h"
#include"Unhide.h"
#include"Translate.h"
#include"Save.h"

class CommandPrompt{
private:
	ShapeFactory factory;
	unsigned idCounter = 0;
public:
	CommandPrompt();

	~CommandPrompt();

	unsigned retrieveCurrentID();
	void retrieveFromFile();
	void inputId();
	void inputData(const char*);
	void executeCommands();

};

