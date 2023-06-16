#include "Square.h"

Square::Square(const Point& pa, const Point& pb, const Point& pc, const Point& pd): Parallelogram(pa, pb, pc, pd)
{
}

Square::Square()
{
}

std::string Square::type() const
{
    return "Negyzet";
}
