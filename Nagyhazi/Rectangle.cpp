#include "Rectangle.h"

Rectangle::Rectangle(const Point& pa, const Point& pb, const Point& pc, const Point& pd): Parallelogram(pa, pb, pc, pd)
{
}

Rectangle::Rectangle()
{
}

std::string Rectangle::type() const
{
	return "Teglalap";
}
