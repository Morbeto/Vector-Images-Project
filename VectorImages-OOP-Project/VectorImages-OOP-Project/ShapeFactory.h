#include"Rectangle.h"
#include"Polygon.h"
#include"Arc.h"
#include"Segment.h"

class ShapeFactory {
private:
	Shape** shapes;
	size_t capacity;
	size_t counter = 0;
public:
	ShapeFactory();
	ShapeFactory(const ShapeFactory&);
	ShapeFactory& operator=(const ShapeFactory&);

	ShapeFactory(ShapeFactory&&)noexcept;
	ShapeFactory& operator=(ShapeFactory&&) noexcept;

	~ShapeFactory();

	Shape*& getShape(size_t index);
	size_t getCounter() const;

	virtual void addShape(const Shape&);
	virtual void addShape(Shape* shape);
	virtual void removeShape(unsigned id_);
	void printAll();

private:
	void copyFrom(const ShapeFactory&);
	void moveFrom(ShapeFactory&&);
	void resize(size_t cap);
	void free();
};