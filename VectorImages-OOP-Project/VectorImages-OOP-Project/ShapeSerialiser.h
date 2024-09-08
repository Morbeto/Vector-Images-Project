#pragma once
#include<fstream>
#include"Drawer.h"
class ShapeSerialiser {
public:
	virtual ~ShapeSerialiser() = default;
	virtual void save(std::ofstream& file) = 0;

	virtual void download(std::ifstream& file,Shape*&) = 0;
};