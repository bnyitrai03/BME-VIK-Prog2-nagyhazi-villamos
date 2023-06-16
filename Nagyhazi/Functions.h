#pragma once
#include "Square.h"
#include "SetofPoints.h"
#include <iostream>
using namespace std;

bool deletearray(Quadrilateral** array, int length);

Quadrilateral* categorize(SetofPoints& set)                                                                                           //eld�nti a ponthalmazr�l, hogy milyen n�gysz�g, ha egy�ltal�n n�gysz�g
{

	if (set.isQuadrilateral())
	{
		if (set.isTrapezoid())
		{
			if (set.isParallelogram())
			{
				if (set.isRectangle())
				{
					if (set.isSquare())
					{
						Square* ptr = new Square(set.geta(), set.getb(), set.getc(), set.getd());                                      //a n�gy pont egy n�gysz�get defini�l, foglalunk neki dinamikusan mem�ri�t
						dynamic_cast<Quadrilateral*>(ptr);
						if (ptr == NULL)
							cout << "Hiba tortent tipuskonverzio kozben!" << endl;
						return ptr;

					}
					else
					{
						Rectangle* ptr = new Rectangle(set.geta(), set.getb(), set.getc(), set.getd());						             //a n�gy pont egy t�glalapot defini�l, foglalunk neki dinamikusan mem�ri�t
					    dynamic_cast<Quadrilateral*>(ptr);
						if (ptr == NULL)
							cout << "Hiba tortent tipuskonverzio kozben!" << endl;
						return ptr;
					}
				}
				if (set.isRhombus())
				{
					if (set.isSquare())
					{
						Square* ptr = new Square(set.geta(), set.getb(), set.getc(), set.getd());                                        //a n�gy pont egy n�gyzetet defini�l, foglalunk neki dinamikusan mem�ri�t
						dynamic_cast<Quadrilateral*>(ptr);
						if (ptr == NULL)
							cout << "Hiba tortent tipuskonverzio kozben!" << endl;
						return ptr;
					}
					else
					{
						Rhombus* ptr = new Rhombus(set.geta(), set.getb(), set.getc(), set.getd());                                       //a n�gy pont egy rombuszt defini�l, foglalunk neki dinamikusan mem�ri�t
						dynamic_cast<Quadrilateral*>(ptr);
						if (ptr == NULL)
							cout << "Hiba tortent tipuskonverzio kozben!" << endl;
						return ptr;
					}

				}
				else
				{
					Parallelogram* ptr = new Parallelogram(set.geta(), set.getb(), set.getc(), set.getd());                               //a n�gy pont egy paralelogramm�t defini�l foglalunk neki dinamikusan mem�ri�t
					dynamic_cast<Quadrilateral*>(ptr);
					if (ptr == NULL)
						cout << "Hiba tortent tipuskonverzio kozben!" << endl;
					return ptr;
				}

			}
			else
			{
				Trapezoid* ptr = new Trapezoid(set.geta(), set.getb(), set.getc(), set.getd());                                          //a n�gy pont egy trap�zt defini�l, foglalunk neki dinamikusan mem�ri�t
				dynamic_cast<Quadrilateral*>(ptr);
				if (ptr == NULL)
					cout << "Hiba tortent tipuskonverzio kozben!" << endl;
				return ptr;
			}

		}
		else
		{
			Quadrilateral* ptr = new Quadrilateral(set.geta(), set.getb(), set.getc(), set.getd());			                             //a n�gy pont egy �ltal�nos n�gysz�get defini�l, foglalunk neki dinamikusan mem�ri�t
			return ptr;
		}



	}
	else
		return NULL;                                                                                                                    //a n�gy pont nem defini�l n�gysz�get, ekkor NULL pointert adunk vissza
}

Quadrilateral** initialize(ifstream& input, int& lengthofcollection)
{
	Point inputPoints[4];                                                                 //bemeneti pontokat t�roljuk benne
	Quadrilateral** arrayofQuadrilaterals = NULL;                                          //heterog�n kollekci�
	SetofPoints inputSet;                                                                  //erre h�vjuk meg a t�pusba sorol� f�ggv�nyt
	Quadrilateral* newQuadrilateralptr;                                                    //ez a t�pusba sorolt n�gysz�gre mutat� pointer

	while (!input.eof())
	{
		for (int i = 0; i < 4; i++)
		{
			if (inputPoints[i].readfromfile(input) == -1)
			{
				cout << "Hibas a bemeneti fajl!" << endl;
				return arrayofQuadrilaterals;
			}

		}

		inputSet.seta(inputPoints[0]);                                                           //be�ll�tjuk a Setofpoints 4 koordin�t�j�t a beolvasott param�terekre
		inputSet.setb(inputPoints[1]);
		inputSet.setc(inputPoints[2]);
		inputSet.setd(inputPoints[3]);

		newQuadrilateralptr = categorize(inputSet);                                             //eld�nti , hogy milyen n�gysz�g, ha nem n�gysz�g NULL pointert add vissza
		if (newQuadrilateralptr == NULL)
		{
			cout << "Ezek a koordinatak nem alkotnak negyszoget: " << endl << inputSet << endl;
		}

		if (newQuadrilateralptr != NULL)
		{  
			Quadrilateral** tmp = new Quadrilateral * [lengthofcollection + 1];                  //ha n�gysz�g a ponthalmaz felvessz�k a heterog�n kollekci�ba
			for (int i = 0; i < lengthofcollection; i++)
			{
				tmp[i] = arrayofQuadrilaterals[i];                                               //�tm�soljuk az eddigi n�gysz�geket
			}
			delete[] arrayofQuadrilaterals;
			tmp[lengthofcollection] = newQuadrilateralptr;                                        //berakjuk az �j n�gysz�get a heterog�n kollekci�ba
			lengthofcollection++;
			arrayofQuadrilaterals = tmp;
		}


	}

	return arrayofQuadrilaterals;
}

void sortandprint(Quadrilateral** array, int length)                                                            //sorba rakja a heterog�n kollekci�t az orig�t�l val� t�vols�g szerint, majd kiiratja ilyen sorrendben a n�gysz�geket
{                         
	int i, j, min_idx;
	for (i = 0; i < length - 1; i++)                                                                            //selection sort-ot haszn�lunk
	{
		min_idx = i;
		for (j = i + 1; j < length; j++)
			if (array[j]->getdistancefromorigin() < array[min_idx]->getdistancefromorigin())                    //megkeress�k a minimumot
				min_idx = j;

		swap(array[min_idx], array[i]);                                                                        //minimumot kicser�lj�k az els� elemmel
	}

	cout << "Az origotol vett tavolsag alapjan sorba rendezett adathalmaz:" << endl;
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << array[i]->type() <<": "<< array[i]->getdistancefromorigin() << endl;
		cout << endl;
	}
}

void swap(Quadrilateral* pmin, Quadrilateral* ptr)                                                           //megcser�lj�k a k�t pointert
{
	Quadrilateral* tmp = pmin;
	pmin = ptr;
	ptr = tmp;
}



bool savetofile(Quadrilateral** array, int length)                                                                                                  //kimenti az adatokat egy f�jlba
{
	string filename = "kimenet.txt";
	ofstream output(filename);
	if (!output) {
		cout << "Hiba tortent a kimeneti fajl megnyitasa soran: " << filename << endl;
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		output << array[i]->geta() << array[i]->getb() << array[i]->getc() << array[i]->getd() << endl;
	}
	
	output.close();
	if (!output) {
		cout << "Hiba tortent a kimeneti fajl bezarasa soran " << filename << endl;
		return false;
	}

	return true;
}

bool deletearray(Quadrilateral** array, int length)                                                                    //felszabad�tja a dinamikusan foglalt mem�ri�t
{
	for (int i = 0; i < length; i++)
	{
		if (array[i]->type() == "Altalanos negyszog")                                                                  //ha Quadrilateral objektumra mutat a pointer, akkor csak sim�n felszabad�tjuk
		{
			delete array[i];
			continue;
		}

		if (array[i]->type() == "Trapez")                                                                              //ha m�smilyen t�pus� objektumra mutat a Quadrilateral pointer, akkor �t kell catolnunk a pointert  
		{                                                                                                              //olyan t�pusra kell castolni, amilyen t�pus� az objektum, hogy megefelel� m�ret� mem�ri�t szabad�tsunk fel 
			Trapezoid* ptr = dynamic_cast<Trapezoid*>(array[i]);                                                       
			if (ptr == NULL)
			{
				cout << "Hiba tortent tipuskonverzio kozben!" << endl;
				return false;
			}
			delete ptr;
			continue;
		}

		if (array[i]->type() == "Paralelogramma")
		{
			Parallelogram* ptr = dynamic_cast<Parallelogram*>(array[i]);
			if (ptr == NULL)
			{
				cout << "Hiba tortent tipuskonverzio kozben!" << endl;
				return false;
			}
			delete ptr;
			continue;
		}

		if (array[i]->type() == "Teglalap")
		{
			Rectangle* ptr = dynamic_cast<Rectangle*>(array[i]);
			if (ptr == NULL)
			{
				cout << "Hiba tortent tipuskonverzio kozben!" << endl;
				return false;
			}
			delete ptr;
			continue;
		}

		if (array[i]->type() == "Rombusz")
		{
			Rhombus* ptr = dynamic_cast<Rhombus*>(array[i]);
			if (ptr == NULL)
			{
				cout << "Hiba tortent tipuskonverzio kozben!" << endl;
				return false;
			}
			delete ptr;
			continue;
		}

		if (array[i]->type() == "Negyzet")
		{
			Square* ptr = dynamic_cast<Square*>(array[i]);
			if (ptr == NULL)
			{
				cout << "Hiba tortent tipuskonverzio kozben!" << endl;
				return false;
			}
			delete ptr;
			continue;
		}

	}

	return true;
}