#include "ArcDrawer.h"

ArcDrawer::ArcDrawer(Arc* arc_, std::ofstream& os) : arc(arc_) {
	draw(os);
}

void ArcDrawer::draw(std::ofstream& svgFile) {
    Point center = arc->operator[](0);
    unsigned radius = arc->getRadius();
    double startAngle = arc->getSmallAngle() * (3.14 / 180.0);
    double endAngle = arc->getLargeAngle() * (3.14 / 180.0);

    double startX = center.getX() + radius * cos(startAngle);
    double startY = center.getY() - radius * sin(startAngle);
    double endX = center.getX() + radius * cos(endAngle);
    double endY = center.getY() - radius * sin(endAngle);

    bool largeArcFlag = (endAngle - startAngle > 3.14) ? 1 : 0;
    bool sweepFlag = 1;

    svgFile << "<path d=\"M " << startX << " " << startY << " "
        << "A " << radius << " " << radius << " 0 "
        << largeArcFlag << " " << sweepFlag << " "
        << endX << " " << endY << "\" "
        << "fill=\"none\" stroke=\"" << arc->getMainColor() << "\" />\n";
}