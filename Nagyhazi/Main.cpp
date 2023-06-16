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



	Quadrilateral** Quadrilateralarray;                                                                                            //heterog�n kollekci�
	int lengthofcollection = 0;                                                                                                    //heterog�n kollekci� hossza
	double rate = 1;                                                                                                               //nagy�t�s ar�nya
	double angle = 0;                                                                                                              //forgat�s sz�ge
	string filename = "bemenet.txt";                                                                                               //input f�jl


	/*ofstream output(filename);
	if (!output) {
		cout << "Hiba tortent a kimeneti fajl megnyitasa soran: " << filename << endl;
		return -1;
	}

	//               T�glalap                 Trap�z                Paralelogramma           Rombusz               N�gyzet                       �ltal�nos n�gysz�g
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
		cout << "Nem erkezett negyszog a bemeneten.";                                                                                                                    //nem �rkezett n�gysz�g a bementei f�jlb�l
		return 0;
	}


	for (int i = 0; i < lengthofcollection; i++)
	{
		cout << *(Quadrilateralarray[i]) << endl;                                                                                                                         //ki�ratjuk az �sszes be�rkez� n�gysz�get                                                                                                                      
	}
	cout << "Transzformaciok megkezdodnek:" << endl;
	cout << endl;
	cout << "Adja meg a nagyitas merteket!" << endl;
	cin >> rate;
	if (cin.fail())                                                                                                                                                    //hib�s inputn�l felszabad�tjuk a dinamikusan foglalt mem�ri�t �s kil�p�nk
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
		Quadrilateralarray[i]->axialreflectiontoY();                                                                                                                   //t�kr�z�s az Y tengelyre
		Quadrilateralarray[i]->axialreflectiontoX();                                                                                                                   //t�kr�z�s az X tengelyre
		Quadrilateralarray[i]->reflectiontotheOrigin();                                                                                                                //orig�ra val� k�z�ppontos t�kr�z�s
		Quadrilateralarray[i]->centralmagnification(rate);                                                                                                             //k�z�ppontos nagy�t�s az orig�ra
		Quadrilateralarray[i]->rotation(angle);                                                                                                                        //orig� k�z�ppont� forgat�s

		cout << endl << endl << endl << endl;
	}                                                                                                                  

    sortandprint(Quadrilateralarray, lengthofcollection);                                                                                                              //sorba rendezi �s ki�rja az adatokat

	if (!savetofile(Quadrilateralarray, lengthofcollection))                                                                                                           //kimenti f�jlba az adatokat
		return -1;

	if (!deletearray(Quadrilateralarray, lengthofcollection))                                                                                                          //felszabad�tja a p�ld�nyokat
		return -1;

	delete[] Quadrilateralarray;
	


	return 0;
}