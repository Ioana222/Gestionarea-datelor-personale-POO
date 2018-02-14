#pragma once
#include "Data.h"
#include "Incasari.h"
#include "Interfata.h"



class Persoana:virtual public Interfata
{
private:
	char nume[40]; 
	char prenume[40]; 
	char adresa[40];
	char cnp[14];
	char suma_asigurare[15];
	Data *data_nastere;
	Incasari *incasare; 

public:
	Persoana();
	Persoana(char nume[], char prenume[], char adresa[],char suma_asigurarem[], char cnp[], char suma_asigurare[]); 
	~Persoana();
	char *getCNP();
	char *getSumaAsigurare();
	char *getNume()
	{
		return nume;
	}
	void Citire(FILE *file);
	void modifica_date_clienti_fisier(FILE *file,FILE *fil2, char nume[],double suma);
	void Afisare();
	Data *getDataNastere();
	void Afisare_data_nastere();
	void Suma_achitata();
	void IncasariFinale();
	
};
