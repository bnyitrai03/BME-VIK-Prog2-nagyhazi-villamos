#pragma once
#define _USE_MATH_DEFINES
#include "Quadrilateral.h"
#include <math.h>
using namespace std;

Quadrilateral::Quadrilateral(const Point& pa, const Point& pb, const Point& pc, const Point& pd): SetofPoints(pa,pb,pc,pd)  
{
	middle = calculatemiddle(pa, pb, pc, pd);                                                                               
	distancefromorigin = middle.distance(Point(0, 0));
}

Quadrilateral::Quadrilateral(const Quadrilateral& other): SetofPoints(other.geta(), other.getb(), other.getc(), other.getd())
{
	middle = other.middle;
	distancefromorigin = other.distancefromorigin;
}



Quadrilateral::Quadrilateral()
{
}

const Point& Quadrilateral::getmiddle() const
{
	return middle;
}

double Quadrilateral::getdistancefromorigin() const
{
	return distancefromorigin;
}

std::string Quadrilateral::type() const
{
	return "Altalanos negyszog";
}

void Quadrilateral::axialreflectiontoY()
{

	a.reflecttoY();                                                                                                        //t�kr�zz�k mind a 4 cs�cs�t az Y tengelyre
	b.reflecttoY();
	c.reflecttoY();
	d.reflecttoY();

	cout << "Az Y tengelyre valo tukrozes utan:" << endl << *this << endl;
}

void Quadrilateral::axialreflectiontoX()
{

	a.reflecttoX();                                                                                                        //t�kr�zz�k mind a 4 cs�cs�t az X tengelyre
	b.reflecttoX();
	c.reflecttoX();
	d.reflecttoX();

	calculatemiddle();
	distancefromorigin = middle.distance(Point(0, 0));
	cout << "Az X tengelyre valo tukrozes utan:" << endl << *this << endl;
}

void Quadrilateral::reflectiontotheOrigin()
{

	a.reflecttotheOrigin();                                                                                                        //t�kr�zz�k mind a 4 cs�cs�t az orig�ra
	b.reflecttotheOrigin();
	c.reflecttotheOrigin();
	d.reflecttotheOrigin();

	calculatemiddle();
	distancefromorigin = middle.distance(Point(0, 0));
	cout << "Az origora valo kozeppontos tukrozes utan:" << endl << *this << endl;
}

void Quadrilateral::centralmagnification(double rate)
{ 
	if (rate == 0)
	{
		cout << "Nem lehet 0-szorosra nagyitani!" << endl;
		return;
	}
	if (rate < 0)
	{
		cout << "Nem lehet negativ-szorosra nagyitani!" << endl;
		return;
	}

	a.setx(a.getx() * rate);                                                                                                       //orig�ra �gy nagy�tunk, hogy megszorozzuk az x �s az y koordin�t�t annyival, ah�nyszoros�ra nagy�tani akarunk
	a.sety(a.gety() * rate);

	b.setx(b.getx() * rate);
	b.sety(b.gety() * rate);

	c.setx(c.getx() * rate);
	c.sety(c.gety() * rate);

	d.setx(d.getx() * rate);
	d.sety(d.gety() * rate);

	calculatemiddle();                                                                                                              //nagy�t�s ut�n ki kell sz�molni a n�gysz�g �j k�z�ppontj�t, �s annak az orig�t�l vett t�vols�g�t
	distancefromorigin = middle.distance(Point(0, 0));                

	cout << "Az origora vett " << rate <<"-szeres nagyitas utan : " << endl << *this << endl;
}

void Quadrilateral::rotation(double angle)
{
	double rad = angle * (M_PI / 180.0);                                                                                            //sin �s cos f�ggv�nyek radi�nnal sz�molnak

	a.setx(a.getx() * cos(rad)  -  a.gety() * sin(rad));                                                                            //az orig� k�r�li forgat�s m�trix-al �sszeszorozzuk a 4 cs�csot
	a.sety((a.getx() * sin(rad) + a.gety() * cos(rad)));                                                                            // x' = x*cos(alfa) - y*sin(alfa)
                                                                                                                                    // y' = x*sin(alfa) - y*cos(alfa)
	b.setx(b.getx() * cos(rad) - b.gety() * sin(rad));
	b.sety(b.getx() * sin(rad) + b.gety() * cos(rad));

	c.setx(c.getx() * cos(rad) - c.gety() * sin(rad));
	c.sety(c.getx() * sin(rad) + c.gety() * cos(rad));

	d.setx(d.getx() * cos(rad) - d.gety() * sin(rad));
	d.sety(d.getx() * sin(rad) + d.gety() * cos(rad));

	calculatemiddle();                                                                                                              //forgat�s ut�n ki kell sz�molni a n�gysz�g �j k�z�ppontj�t
	distancefromorigin = middle.distance(Point(0, 0));

	cout << "Az origora vett " << angle << " fokos forgatas utan : " << endl << *this << endl;

}


Point Quadrilateral::calculatemiddle(const Point& a, const Point& b, const Point& c, const Point& d)
{
	return Point( (a.getx() + b.getx() + c.getx() + d.getx() ) / 4 , (a.gety() + b.gety() + c.gety() + d.gety()) / 4 );        //n�gysz�g k�z�ppontja a n�gy cs�cs�nak a sz�mtani k�zepe
}

void Quadrilateral::calculatemiddle()
{
	middle.setx((a.getx() + b.getx() + c.getx() + d.getx()) / 4);                                                             //n�gysz�g k�z�ppontja a n�gy cs�cs�nak a sz�mtani k�zepe                    
    middle.sety((a.gety() + b.gety() + c.gety() + d.gety()) / 4);
}

std::ostream& operator<<(std::ostream& os, const Quadrilateral& q)
{
	os << q.type() << " koordinatai: " << endl << "   a: " << q.geta() << "   " << "b: " << q.getb() << "   " << "c: " << q.getc() << "   " << "d: " << q.getd() << "kozeppontja: " << q.getmiddle();
	return os;
}
