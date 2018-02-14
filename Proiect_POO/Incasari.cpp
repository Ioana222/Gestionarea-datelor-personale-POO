#include <stdio.h>
#include<string>
#include <iostream>
#include "Persoana.h"
#include "Incasari.h"
using namespace std;

Incasari::Incasari()
{
	suma_incasata = 0;
	rest = 0;
	suma_ramasa_de_achitat = 0;

}
Incasari::~Incasari()
{
	cout << "S-a apelat destructorul din Incasari." << endl;
}

Incasari::Incasari(double suma_incasata, double rest, double suma_ramasa_de_achitat)
{
	this->suma_incasata = suma_incasata;
	this->rest = rest;
	this->suma_ramasa_de_achitat = suma_ramasa_de_achitat;
}

double Incasari::getRest()
{
	return this->rest;
}

double Incasari::getSuma_Incasata()
{
	return this->suma_incasata;
}

double Incasari::getSuma_Ramasa_achitat()
{
	return this->suma_ramasa_de_achitat;
}

void Incasari::setRest(double x)
{
	this->rest = x;
}

void Incasari::setSuma_Incasata(double y)
{
	this->suma_incasata = y;
}

void Incasari::setSuma_ramasa_achitat(double z)
{
	this->suma_ramasa_de_achitat = z;
}


