#pragma once
#include "ShapeSerialiser.h"

class SegmentSerialiser : public ShapeSerialiser {
private:
	 Segment* seg;
public:
	SegmentSerialiser(std::ofstream& file, Segment*);
	SegmentSerialiser(std::ifstream& file, Shape*&);

	void save(std::ofstream& file) override;
	void download(std::ifstream& file,Shape*&) override;
};
