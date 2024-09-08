#include "RectangleDrawer.h"

RectangleDrawer::RectangleDrawer(Rectangle* rect, std::ofstream& os) : temp(rect) {
	draw(os);
}

void RectangleDrawer::draw(std::ofstream& svgFile) {
	svgFile << "  <rect x=\"" << temp->operator[](0).getX() << "\" y=\"" << temp->operator[](0).getY() << "\" "
		<< "width=\"" << temp->getWidth() << "\" height=\"" << temp->getHeight() << "\" "
		<< "fill=\"" << temp->getSideColor() << "\" "
		<< "stroke=\"" << temp->getMainColor() << "\" />\n";
}