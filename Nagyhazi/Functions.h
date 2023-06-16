#pragma once
#include "Square.h"
#include "SetofPoints.h"
#include <iostream>
using namespace std;

bool deletearray(Quadrilateral** array, int length);

Quadrilateral* categorize(SetofPoints& set)                                                                                           //eldönti a ponthalmazról, hogy milyen négyszög, ha egyáltalán négyszög
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
						Square* ptr = new Square(set.geta(), set.getb(), set.getc(), set.getd());                                      //a négy pont egy négyszöget definiál, foglalunk neki dinamikusan memóriát
						dynamic_cast<Quadrilateral*>(ptr);
						if (ptr == NULL)
							cout << "Hiba tortent tipuskonverzio kozben!" << endl;
						return ptr;

					}
					else
					{
						Rectangle* ptr = new Rectangle(set.geta(), set.getb(), set.getc(), set.getd());						             //a négy pont egy téglalapot definiál, foglalunk neki dinamikusan memóriát
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
						Square* ptr = new Square(set.geta(), set.getb(), set.getc(), set.getd());                                        //a négy pont egy négyzetet definiál, foglalunk neki dinamikusan memóriát
						dynamic_cast<Quadrilateral*>(ptr);
						if (ptr == NULL)
							cout << "Hiba tortent tipuskonverzio kozben!" << endl;
						return ptr;
					}
					else
					{
						Rhombus* ptr = new Rhombus(set.geta(), set.getb(), set.getc(), set.getd());                                       //a négy pont egy rombuszt definiál, foglalunk neki dinamikusan memóriát
						dynamic_cast<Quadrilateral*>(ptr);
						if (ptr == NULL)
							cout << "Hiba tortent tipuskonverzio kozben!" << endl;
						return ptr;
					}

				}
				else
				{
					Parallelogram* ptr = new Parallelogram(set.geta(), set.getb(), set.getc(), set.getd());                               //a négy pont egy paralelogrammát definiál foglalunk neki dinamikusan memóriát
					dynamic_cast<Quadrilateral*>(ptr);
					if (ptr == NULL)
						cout << "Hiba tortent tipuskonverzio kozben!" << endl;
					return ptr;
				}

			}
			else
			{
				Trapezoid* ptr = new Trapezoid(set.geta(), set.getb(), set.getc(), set.getd());                                          //a négy pont egy trapézt definiál, foglalunk neki dinamikusan memóriát
				dynamic_cast<Quadrilateral*>(ptr);
				if (ptr == NULL)
					cout << "Hiba tortent tipuskonverzio kozben!" << endl;
				return ptr;
			}

		}
		else
		{
			Quadrilateral* ptr = new Quadrilateral(set.geta(), set.getb(), set.getc(), set.getd());			                             //a négy pont egy általános négyszöget definiál, foglalunk neki dinamikusan memóriát
			return ptr;
		}



	}
	else
		return NULL;                                                                                                                    //a négy pont nem definiál négyszöget, ekkor NULL pointert adunk vissza
}

Quadrilateral** initialize(ifstream& input, int& lengthofcollection)
{
	Point inputPoints[4];                                                                 //bemeneti pontokat tároljuk benne
	Quadrilateral** arrayofQuadrilaterals = NULL;                                          //heterogén kollekció
	SetofPoints inputSet;                                                                  //erre hívjuk meg a típusba soroló függvényt
	Quadrilateral* newQuadrilateralptr;                                                    //ez a típusba sorolt négyszögre mutató pointer

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

		inputSet.seta(inputPoints[0]);                                                           //beállítjuk a Setofpoints 4 koordinátáját a beolvasott paraméterekre
		inputSet.setb(inputPoints[1]);
		inputSet.setc(inputPoints[2]);
		inputSet.setd(inputPoints[3]);

		newQuadrilateralptr = categorize(inputSet);                                             //eldönti , hogy milyen négyszög, ha nem négyszög NULL pointert add vissza
		if (newQuadrilateralptr == NULL)
		{
			cout << "Ezek a koordinatak nem alkotnak negyszoget: " << endl << inputSet << endl;
		}

		if (newQuadrilateralptr != NULL)
		{  
			Quadrilateral** tmp = new Quadrilateral * [lengthofcollection + 1];                  //ha négyszög a ponthalmaz felvesszük a heterogén kollekcióba
			for (int i = 0; i < lengthofcollection; i++)
			{
				tmp[i] = arrayofQuadrilaterals[i];                                               //átmásoljuk az eddigi négyszögeket
			}
			delete[] arrayofQuadrilaterals;
			tmp[lengthofcollection] = newQuadrilateralptr;                                        //berakjuk az új négyszöget a heterogén kollekcióba
			lengthofcollection++;
			arrayofQuadrilaterals = tmp;
		}


	}

	return arrayofQuadrilaterals;
}

void sortandprint(Quadrilateral** array, int length)                                                            //sorba rakja a heterogén kollekciót az origótól való távolság szerint, majd kiiratja ilyen sorrendben a négyszögeket
{                         
	int i, j, min_idx;
	for (i = 0; i < length - 1; i++)                                                                            //selection sort-ot használunk
	{
		min_idx = i;
		for (j = i + 1; j < length; j++)
			if (array[j]->getdistancefromorigin() < array[min_idx]->getdistancefromorigin())                    //megkeressük a minimumot
				min_idx = j;

		swap(array[min_idx], array[i]);                                                                        //minimumot kicseréljük az elsõ elemmel
	}

	cout << "Az origotol vett tavolsag alapjan sorba rendezett adathalmaz:" << endl;
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << array[i]->type() <<": "<< array[i]->getdistancefromorigin() << endl;
		cout << endl;
	}
}

void swap(Quadrilateral* pmin, Quadrilateral* ptr)                                                           //megcseréljük a két pointert
{
	Quadrilateral* tmp = pmin;
	pmin = ptr;
	ptr = tmp;
}



bool savetofile(Quadrilateral** array, int length)                                                                                                  //kimenti az adatokat egy fájlba
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

bool deletearray(Quadrilateral** array, int length)                                                                    //felszabadítja a dinamikusan foglalt memóriát
{
	for (int i = 0; i < length; i++)
	{
		if (array[i]->type() == "Altalanos negyszog")                                                                  //ha Quadrilateral objektumra mutat a pointer, akkor csak simán felszabadítjuk
		{
			delete array[i];
			continue;
		}

		if (array[i]->type() == "Trapez")                                                                              //ha másmilyen típusú objektumra mutat a Quadrilateral pointer, akkor át kell catolnunk a pointert  
		{                                                                                                              //olyan típusra kell castolni, amilyen típusú az objektum, hogy megefelelõ méretû memóriát szabadítsunk fel 
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