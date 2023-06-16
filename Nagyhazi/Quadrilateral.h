#pragma once
#include "SetofPoints.h"
#include <iostream>

class Quadrilateral: public SetofPoints
{
protected:
	Point middle;                                                                                                          //n�gysz�g k�z�ppontja: koordin�t�inak sz�mtani k�zepe                  
	double distancefromorigin;                                                                                             //n�gysz�g k�z�ppontj�nak az orig�t�l m�rt t�vols�ga

public:
	Quadrilateral(const Point& pa, const Point& pb, const Point& pc, const Point& pd);
	Quadrilateral(const Quadrilateral&);
	Quadrilateral();

	const Point& getmiddle()const;
	double getdistancefromorigin()const;

	virtual std::string type()const;                                                                                       //visszaadja az objektum t�pus�t

	void axialreflectiontoY();                                                                                             //Y tengelyre t�kr�z�s
	void axialreflectiontoX();                                                                                             //X tengelyre t�kr�z�s
	void reflectiontotheOrigin();                                                                                          //k�z�ppontos t�kr�z�s az orig�ra
	void centralmagnification(double);                                                                                     //k�z�ppontos nagy�t�s az orig�ra
	void rotation(double);                                                                                                 //forgat�s orig� k�z�pponttal

	Point calculatemiddle( const Point& , const Point& , const Point& , const Point&);                                      //n�gysz�g k�z�ppontj�nak kisz�m�t�sa
	void calculatemiddle();                                                                                                 //megv�ltozott k�z�ppont be�ll�t�s�ra szolg�l

};


std::ostream& operator <<(std::ostream& , const Quadrilateral&);                                                            