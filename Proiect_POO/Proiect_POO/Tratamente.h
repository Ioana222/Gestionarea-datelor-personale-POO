#pragma once;
#include "Persoana.h"

class Tratamente :virtual public Interfata
{
private:
	char boli[40];
	char tratamente[40];
public:
	Tratamente();
	Tratamente(char boli[], char tratamente[]);
	~Tratamente();
	void Afisare();
	char *GetBoli();
	char *GetTratamente();
	void Citire(FILE *file_boli_tratamente);
	void Citire();


};