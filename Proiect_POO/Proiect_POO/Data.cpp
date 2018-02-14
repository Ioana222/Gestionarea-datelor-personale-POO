#include	<stdio.h>
#include	<iostream>
#include	"Persoana.h"

using namespace std;
Data::Data()
{
	this->an = 0;
	this->luna = 0;
	this->zi = 0;
	this->varsta = 0;
}

Data::Data(char cnp[])
{
	this->an = 0;
	this->luna = 0;
	this->zi = 0;
}
Data::Data(int an, int luna, int zi, int varsta)
{
	this->an = an;
	this->luna = luna;
	this->zi = zi;
	this->varsta = varsta;
}
Data::~Data()
{
	cout << "S-a apelat destructorul din Data.h." << endl;
}
Data *DataNasterii(char cnp[])
{
	Data *d=new Data;
	d->an = 1900 + ((cnp[1] - '0') * 10 + (cnp[2] - '0'));
	d->luna = (cnp[3] - '0') * 10 + (cnp[4] - '0');
	d->zi = (cnp[5] - '0') * 10 + (cnp[6] - '0');
	return d;
}
int Data::getAn()
{
	return an;
}
int Data::getLuna()
{
	return luna;
}
int Data::getZi()
{
	return zi;
}
int Data::getVarsta()
{
	return varsta;
}
int Varsta(char cnp[])
{
	Data *d = new Data;
	d->an = 1900 + ((cnp[1] - '0') * 10 + (cnp[2] - '0'));
	int varsta = 2017 - d->an;
	return varsta;
}