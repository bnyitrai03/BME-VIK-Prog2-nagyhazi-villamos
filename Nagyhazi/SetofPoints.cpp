#pragma once
#include "SetofPoints.h"
#include "Square.h"

using namespace std;

SetofPoints::SetofPoints(): a(0,0), b(0,0), c(0,0), d(0,0)
{
}

SetofPoints::SetofPoints(const Point& pa, const Point& pb, const Point& pc, const Point& pd): a(pa), b(pb), c(pc), d(pd)
{
}

const Point& SetofPoints::geta() const
{
	return a;
}

const Point& SetofPoints::getb() const
{
	return b;
}

const Point& SetofPoints::getc() const
{
	return c;
}

const Point& SetofPoints::getd() const
{
	return d;
}

void SetofPoints::seta(const Point& pa)
{
	a = pa;
}

void SetofPoints::setb(const Point& pb)
{
	b = pb;
}

void SetofPoints::setc(const Point& pc)
{
	c = pc;
}

void SetofPoints::setd(const Point& pd)
{
	d = pd;
}

bool SetofPoints::isQuadrilateral()const
{
	
	if (a == b || a == c || a == d || b == c || b == d || c == d)                                             //ha k�t pont ugyanaz, akkor nem alkotnak n�gysz�get
		return false;

	if ( a.iscollinear(b,c) || a.iscollinear(b,d) || a.iscollinear(c,d) || b.iscollinear(c, d))               //ha h�rom pont egy egyenesre esik, akkor se alkotnak n�gysz�get
		return false;

	return true;
}

bool SetofPoints::isTrapezoid()const                                                                               //ha van egy p�rhuzamos oldalp�rja, akkor trap�z
{
	if (fabs(a.slope(b) - c.slope(d)) < constants::EPSZILON || fabs(b.slope(c) - d.slope(a)) < constants::EPSZILON)
		return true;
	else
		return false;
}

bool SetofPoints::isParallelogram()const                                                                          //ha a szemk�zti oldalai p�ronk�nt p�rhuzamosak, akkor paralelogramma
{
	if (fabs(a.slope(b) - c.slope(d)) < constants::EPSZILON && fabs(b.slope(c) - d.slope(a)) < constants::EPSZILON)
		return true;
	else
		return false;
}

bool SetofPoints::isRectangle()const
{
	if (a.isrightangle(b,c) && b.isrightangle(c,d) && c.isrightangle(d,a) && d.isrightangle(a,b))             //ha mind a n�gy sz�ge der�ksz�g, akkor t�glalap
		return true;
	else
		return false;
}

bool SetofPoints::isRhombus()const
{
	if (a.distance(b) == b.distance(c) && b.distance(c) == c.distance(d) && c.distance(d) == d.distance(a) )        //ha minden oldala egyenl� hossz�, akkor rombusz 
		return true;
	else
		return false;
}

bool SetofPoints::isSquare()const
{
	if (isRhombus() && isRectangle())                                                                               //ha rombusz �s t�glalap, akkor n�gyzet is egy n�gysz�g
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& os, const SetofPoints& set)
{
	os << "   a: " << set.geta() << "   " << "b: " << set.getb() << "   " << "c: " << set.getc() << "   " << "d: " << set.getd() << endl;
	return os;
}
