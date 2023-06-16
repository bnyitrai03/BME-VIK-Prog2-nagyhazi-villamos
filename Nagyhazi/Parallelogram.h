#pragma once
#include "Trapezoid.h"


class Parallelogram: public Trapezoid
{
public:
	Parallelogram();
	Parallelogram(const Point& , const Point& , const Point& , const Point&);
    std::string type()const;
};

