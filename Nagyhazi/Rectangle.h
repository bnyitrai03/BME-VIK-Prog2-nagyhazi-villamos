#pragma once
#include "Parallelogram.h"
class Rectangle: public virtual Parallelogram
{
public:
	Rectangle(const Point& , const Point& , const Point& , const Point&);
	Rectangle();
	std::string type()const;
};

