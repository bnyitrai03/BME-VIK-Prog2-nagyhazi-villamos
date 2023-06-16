#include "Rhombus.h"

Rhombus::Rhombus(const Point& pa, const Point& pb, const Point& pc, const Point& pd): Parallelogram(pa, pb, pc, pd)
{
}

Rhombus::Rhombus()
{
}

std::string Rhombus::type() const
{
	return "Rombusz";
}
