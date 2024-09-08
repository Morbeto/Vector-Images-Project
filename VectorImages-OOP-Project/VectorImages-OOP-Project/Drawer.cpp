#include "Drawer.h"

Drawer::Drawer(const char* filename, ShapeFactory f) {
	std::ofstream file(filename, std::ios::out);

	if (!file) {
		std::cout << "Error!";
		return;
	}
	file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	file << "<svg width=\"" << 800 << "\" height=\"" << 800
		<< "\" xmlns=\"http://www.w3.org/2000/svg\">\n";
	drawShapes(file, f);

	file << "</svg>\n";
	file.close();

}


void Drawer::drawShapes(std::ofstream& file, ShapeFactory f) {

	for (int i = 0; i < f.getCounter(); i++) {

		if (!f.getShape(i)->checkIfHidden()) {
			if (f.getShape(i)->getType() == segment) {
				SegmentDrawer((Segment*)f.getShape(i), file);
			}
			else if (f.getShape(i)->getType() == rectangle) {
				RectangleDrawer((Rectangle*)f.getShape(i), file);
			}
			else if (f.getShape(i)->getType() == arc) {
				ArcDrawer((Arc*)f.getShape(i), file);
			}
			else if (f.getShape(i)->getType() == polygon) {
				PolygonDrawer((Polygon*)f.getShape(i), file);
			}
			else if (f.getShape(i)->getType() == group) {
				ShapeFactory* temp = (Group*)f.getShape(i);
				drawShapes(file, *temp);
			}
			else {
				std::cout << "Undefined.";
			}
		}
	}
}
