#pragma once
#include <iostream>
class Point
{
	double x;                                                                 //egy s�kbeli pont x �s y koordin�t�j�t t�rolja
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

	double distance(const Point&)const;                                       //k�t pont t�vols�ga
	bool iscollinear(const Point& , const Point&)const;                       //eld�nti h�rom pontr�l, hogy egy egyenesre esnek-e
	bool isrightangle(const Point&, const Point&)const;                       //eld�nti h�rom pontr�l, hogy der�ksz�g� h�romsz�get z�rnak-e be
	double slope(const Point&)const;                                          //meghat�rozza a k�t ponton �tmen� egyenes meredeks�g�t
	void reflecttoY();                                                        //Y tengelyre t�kr�z�s
	void reflecttoX();                                                        //X tengelyre t�kr�z�s
	void reflecttotheOrigin();                                                //orig�ra vett k�z�ppontos t�kr�z�s


	Point operator=(const Point&);                                            //�rt�kad�s oper�tor
	bool operator == (const Point&)const;                                     //�sszehasonl�t�s oper�tor

	int readfromfile(std::istream&);                                         //kiolvassa az adatokat a f�jlb�l
};

std::ostream& operator <<(std::ostream& , const Point&);                      //ki�rat� oper�tor

namespace constants
{
	const double EPSZILON = 0.0000000001;                                     //a double aritmetika k�vetkezt�ben == jel helyett haszn�ljuk 
	                                                                          // fabs( a - b ) <= EPSZILON  <--->   a == b 
}