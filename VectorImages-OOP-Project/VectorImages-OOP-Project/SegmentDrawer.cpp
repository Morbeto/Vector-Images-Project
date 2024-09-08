#include "SegmentDrawer.h"
SegmentDrawer::SegmentDrawer( Segment* s , std::ofstream& svg) : temp(s) {
	draw(svg);
};

void SegmentDrawer::draw(std::ofstream& svgFile) {
	svgFile << "<line x1=\"" << temp->operator[](0).getX() << "\" y1=\"" << temp->operator[](0).getY() << "\" "
		<< "x2=\"" << temp->operator[](1).getX() << "\" y2=\"" << temp->operator[](1).getY() << "\" "
		<< "stroke=\"" << temp->getMainColor() << "\" />\n";
}

