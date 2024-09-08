#include "PolygonDrawer.h"
PolygonDrawer::PolygonDrawer(Polygon* poly_, std::ofstream& file) : poly(poly_) {
	draw(file);
}

void PolygonDrawer::draw(std::ofstream& svgFile) {
    size_t numPoints = poly->getPointsCounter();

    svgFile << "<polygon points=\"";
    for (size_t i = 0; i < numPoints; ++i) {
        Point p = poly->operator[](i);
        svgFile << p.getX() << "," << p.getY() << " ";
    }
    svgFile << "\" fill=\"" << poly->getSideColor() << "\" "
        << "stroke=\"" << poly->getMainColor() << "\" />\n";
}