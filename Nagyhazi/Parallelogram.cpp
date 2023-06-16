#include "Parallelogram.h"

Parallelogram::Parallelogram()
{
}

Parallelogram::Parallelogram(const Point& pa, const Point& pb, const Point& pc, const Point& pd): Trapezoid(pa, pb, pc, pd)
{
}

std::string Parallelogram::type()const
{
	return "Paralelogramma";
}
