#pragma once
#include <math.h>
#include <fstream>
#include "Point.h"



Point::Point(): x(0), y(0)
{
}

Point::Point(double px, double py): x(px), y(py)
{
}

Point::Point(const Point& other): x(other.x), y(other.y)
{
}

void Point::setPoint(double px=0, double py=0)
{
	x = px;
	y = py;
}

double Point::getx() const
{
	return x;
}

double Point::gety() const
{
	return y;
}

void Point::setx(double px)
{
	x = px;
}

void Point::sety(double py)
{
	y = py;
}

double Point::distance(const Point& b)const
{
	return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}

bool Point::iscollinear(const Point& b, const Point& c)const
{
	if ( fabs (0.5 * (x * (b.gety() - c.gety()) + b.getx() * (c.gety() - y) + c.getx() * (y - b.gety() ) ) ) <= constants::EPSZILON)                             //három pont által alkotott háromszög területe == 0, akkor egy egyenesre esnek
		return true;
	else
		return false;
}

bool Point::isrightangle(const Point& b, const Point& c)const
{
	double lengtha = this->distance(b);                                                                                                             //kiszámolja, hogy három pont által határolt a-b-c háromszög a és b oldala között fekvõ szög derékszög-e
	double lengthb = b.distance(c);
	double lengthc = this->distance(c);

	double cosalfa = (lengtha * lengtha + lengthb * lengthb - lengthc * lengthc) / 2 * lengtha * lengthb;                                           //a szöget a koszinusztétel segítségével számoljuk ki

	if (cosalfa < constants::EPSZILON)                                                                                                              //ha a szög koszinusza nulla, akkor derékszög  
		return true;
	else
	    return false;
}

double Point::slope(const Point& b)const
{
	if (fabs(x - b.getx()) <= constants::EPSZILON)                                                                                                 //ha az y tengellyel párhuzamos az egyenes, akkor nincs értelmezve a merdeksége, önkényesen 1 lesz a meredeksége
		return 1;
	return (b.gety() - y) / (b.getx() - x);                                                                                                         //meredekség = delta y /delta x
}

void Point::reflecttoY()                                                                                                                            //pontot úgy tükrözünk az y tengelyre, hogy az x koordinátájának az elõjelét megcseréljük
{
	x = (- 1) * x;
}

void Point::reflecttoX()
{
	y = (-1) * y;                                                                                                                                  //pontot úgy tükrözünk az x tengelyre, hogy az y koordinátájának az elõjelét megcseréljük
}

void Point::reflecttotheOrigin()                                                                                                                  //pontot úgy tükrözünk az origóra, hogy az x és y koordinátáinak az elõjelét megcseréljük
{
	x = (-1) * x;
	y = (-1) * y;
}

Point Point::operator=(const Point& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

bool Point::operator==(const Point& other)const
{
	if (fabs (x - other.x) < constants::EPSZILON && fabs(y - other.y) < constants::EPSZILON )
		return true;
	else
		return false;
}

int Point::readfromfile(std::istream& is)
{
	
	is >> x >> y;
	if (is.fail())
	{
		return -1;
	}
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << p.getx() << " " << p.gety() << std::endl;
	return os;
}

