#include "Trapezoid.h"

Trapezoid::Trapezoid(const Point& pa, const Point& pb, const Point& pc, const Point& pd): Quadrilateral(pa, pb, pc, pd)
{
}

Trapezoid::Trapezoid()
{
}

std::string Trapezoid::type()const
{
    return "Trapez";
}
