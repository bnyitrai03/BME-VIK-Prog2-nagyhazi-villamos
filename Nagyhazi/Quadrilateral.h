#pragma once
#include "SetofPoints.h"
#include <iostream>

class Quadrilateral: public SetofPoints
{
protected:
	Point middle;                                                                                                          //négyszög középpontja: koordinátáinak számtani közepe                  
	double distancefromorigin;                                                                                             //négyszög középpontjának az origótól mért távolsága

public:
	Quadrilateral(const Point& pa, const Point& pb, const Point& pc, const Point& pd);
	Quadrilateral(const Quadrilateral&);
	Quadrilateral();

	const Point& getmiddle()const;
	double getdistancefromorigin()const;

	virtual std::string type()const;                                                                                       //visszaadja az objektum típusát

	void axialreflectiontoY();                                                                                             //Y tengelyre tükrözés
	void axialreflectiontoX();                                                                                             //X tengelyre tükrözés
	void reflectiontotheOrigin();                                                                                          //középpontos tükrözés az origóra
	void centralmagnification(double);                                                                                     //középpontos nagyítás az origóra
	void rotation(double);                                                                                                 //forgatás origó középponttal

	Point calculatemiddle( const Point& , const Point& , const Point& , const Point&);                                      //négyszög középpontjának kiszámítása
	void calculatemiddle();                                                                                                 //megváltozott középpont beállítására szolgál

};


std::ostream& operator <<(std::ostream& , const Quadrilateral&);                                                            