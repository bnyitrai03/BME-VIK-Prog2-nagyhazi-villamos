#pragma once
#define MEMTRACE
#include <iostream>
#include <fstream>
#include "memtrace.h"
#include "Functions.h"
#include "Square.h"

using namespace std;

int main()
{



	Quadrilateral** Quadrilateralarray;                                                                                            //heterogén kollekció
	int lengthofcollection = 0;                                                                                                    //heterogén kollekció hossza
	double rate = 1;                                                                                                               //nagyítás aránya
	double angle = 0;                                                                                                              //forgatás szöge
	string filename = "bemenet.txt";                                                                                               //input fájl


	/*ofstream output(filename);
	if (!output) {
		cout << "Hiba tortent a kimeneti fajl megnyitasa soran: " << filename << endl;
		return -1;
	}

	//               Téglalap                 Trapéz                Paralelogramma           Rombusz               Négyzet                       Általános négyszög
	//output << " 0 -4  6 -2 3 7 -3 5       3 -7 5 -1 4 1 -2 3       0 0 9 0 16 5 7 5      1 1 5 3 7 7 3 5    -1 -3 5 -1 3 5 -3 3       -1.99778  0.587889   -0.409992 -0.97233    -0.35344 1.6155   0.70655 1.003442"; 
	output << "0.3333 0.3333  0.171818 0.3333 333333 72 -34444 511";
	output.close();

	if (!output) {
		cout << "Hiba tortent a kimeneti fajl bezarasa soran: " << filename << endl;
		return -1;
	}*/


	ifstream input(filename);
	if (!input) {
		cout << "Hiba tortent a bemeneti fajl megnyitasa soran: " << filename << endl;
		return -1;
	}

	Quadrilateralarray = initialize(input, lengthofcollection);

	input.close();
	if (!input) {
		cout << "Hiba tortent a bemeneti fajl bezarasa soran: " << filename << endl;
		deletearray(Quadrilateralarray, lengthofcollection);
		delete[] Quadrilateralarray;
		return -1;
	}
	if (Quadrilateralarray == NULL)
	{
		cout << "Nem erkezett negyszog a bemeneten.";                                                                                                                    //nem érkezett négyszög a bementei fájlból
		return 0;
	}


	for (int i = 0; i < lengthofcollection; i++)
	{
		cout << *(Quadrilateralarray[i]) << endl;                                                                                                                         //kiíratjuk az összes beérkezõ négyszöget                                                                                                                      
	}
	cout << "Transzformaciok megkezdodnek:" << endl;
	cout << endl;
	cout << "Adja meg a nagyitas merteket!" << endl;
	cin >> rate;
	if (cin.fail())                                                                                                                                                    //hibás inputnál felszabadítjuk a dinamikusan foglalt memóriát és kilépünk
	{
		cout << "Hibas user input!" << endl;
		deletearray(Quadrilateralarray, lengthofcollection);
		delete[] Quadrilateralarray;
		return -1;
	}
	cout << "Adja meg a forgatas szoget!" << endl;
	cin >> angle;
	if (cin.fail())
	{
		cout << "Hibas user input!" << endl;
		deletearray(Quadrilateralarray, lengthofcollection);
		delete[] Quadrilateralarray;
		return -1;
	}
	cout << endl;
	for  (int i = 0; i < lengthofcollection; i++)
	{
		cout << *(Quadrilateralarray[i]) << endl;
		Quadrilateralarray[i]->axialreflectiontoY();                                                                                                                   //tükrözés az Y tengelyre
		Quadrilateralarray[i]->axialreflectiontoX();                                                                                                                   //tükrözés az X tengelyre
		Quadrilateralarray[i]->reflectiontotheOrigin();                                                                                                                //origóra való középpontos tükrözés
		Quadrilateralarray[i]->centralmagnification(rate);                                                                                                             //középpontos nagyítás az origóra
		Quadrilateralarray[i]->rotation(angle);                                                                                                                        //origó középpontú forgatás

		cout << endl << endl << endl << endl;
	}                                                                                                                  

    sortandprint(Quadrilateralarray, lengthofcollection);                                                                                                              //sorba rendezi és kiírja az adatokat

	if (!savetofile(Quadrilateralarray, lengthofcollection))                                                                                                           //kimenti fájlba az adatokat
		return -1;

	if (!deletearray(Quadrilateralarray, lengthofcollection))                                                                                                          //felszabadítja a példányokat
		return -1;

	delete[] Quadrilateralarray;
	


	return 0;
}