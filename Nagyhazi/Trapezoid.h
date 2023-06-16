#pragma once
#include "Quadrilateral.h"


class Trapezoid: public Quadrilateral
{
public:
	Trapezoid(const Point& , const Point& , const Point& , const Point&);
	Trapezoid();
	std::string type()const;
};

