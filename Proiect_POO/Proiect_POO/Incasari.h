#pragma once
#include <iostream>
#include "Persoana.h"
using namespace std;

class Incasari
{
private:
	double suma_incasata;
	double rest;
	double suma_ramasa_de_achitat;
public:
	Incasari();
	Incasari(double suma_incasata, double rest, double suma_ramasa_de_achitat);
	~Incasari();
	double getRest();
	double getSuma_Incasata();
	double getSuma_Ramasa_achitat();
	void setRest(double rest);
	void setSuma_Incasata(double sumaIncasata);
	void setSuma_ramasa_achitat(double sumaRamasaAcitat);
	

	friend ostream& operator<<(ostream& output, const Incasari &incasari)
	{
		return output << "Rest=  " << incasari.rest << endl << "Suma incasata= "
			<< incasari.suma_incasata << endl << "Suma ramasa de achitat= " << incasari.suma_ramasa_de_achitat;
	} 
};