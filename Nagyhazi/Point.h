#pragma once
#include <iostream>
class Point
{
	double x;                                                                 //egy síkbeli pont x és y koordinátáját tárolja
	double y;

public:
	Point();
	Point(double , double);
	Point(const Point&);

	void setPoint(double, double);

	double getx()const;
	double gety()const;
	void setx(double);
	void sety(double);

	double distance(const Point&)const;                                       //két pont távolsága
	bool iscollinear(const Point& , const Point&)const;                       //eldönti három pontról, hogy egy egyenesre esnek-e
	bool isrightangle(const Point&, const Point&)const;                       //eldönti három pontról, hogy derékszögû háromszöget zárnak-e be
	double slope(const Point&)const;                                          //meghatározza a két ponton átmenõ egyenes meredekségét
	void reflecttoY();                                                        //Y tengelyre tükrözés
	void reflecttoX();                                                        //X tengelyre tükrözés
	void reflecttotheOrigin();                                                //origóra vett középpontos tükrözés


	Point operator=(const Point&);                                            //értékadás operátor
	bool operator == (const Point&)const;                                     //összehasonlítás operátor

	int readfromfile(std::istream&);                                         //kiolvassa az adatokat a fájlból
};

std::ostream& operator <<(std::ostream& , const Point&);                      //kiírató operátor

namespace constants
{
	const double EPSZILON = 0.0000000001;                                     //a double aritmetika következtében == jel helyett használjuk 
	                                                                          // fabs( a - b ) <= EPSZILON  <--->   a == b 
}