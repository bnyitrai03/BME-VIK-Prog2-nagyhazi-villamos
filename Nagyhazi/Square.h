#pragma once
#include "Rectangle.h"
#include "Rhombus.h"
class Square: public Rectangle, public Rhombus
{
public:
	Square(const Point& , const Point& , const Point& , const Point&);
	Square();
	std::string type()const;
};

