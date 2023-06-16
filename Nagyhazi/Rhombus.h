#pragma once

#include "Parallelogram.h"

class Rhombus: public virtual Parallelogram
{
public:
	Rhombus(const Point& , const Point& , const Point& , const Point&);
	Rhombus();
	std::string type()const;
};

