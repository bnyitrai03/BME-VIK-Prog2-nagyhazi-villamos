#pragma once
#include "Point.h"

class SetofPoints
{
protected:
	Point a;                                                                              //a ponthalmaz négy csúcsának koordinátái
	Point b;
	Point c;
	Point d;

public:
	SetofPoints();
	SetofPoints(const Point& , const Point& , const Point& , const Point&);

	const Point& geta() const;
	const Point& getb() const;
	const Point& getc() const;
	const Point& getd() const;

	void seta(const Point&);
	void setb(const Point&);
	void setc(const Point&);
	void setd(const Point&);
                   

	bool isQuadrilateral()const;                                                               //ezek a függvények döntik el, hogy az adott ponthalmaz milyen négyszöget alkot a síkon
	bool isTrapezoid()const;
	bool isParallelogram()const;
	bool isRectangle()const;
	bool isRhombus()const;
	bool isSquare()const;


};

std::ostream& operator <<(std::ostream&, const SetofPoints&); 