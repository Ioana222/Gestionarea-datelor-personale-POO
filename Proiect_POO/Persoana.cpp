#include	<string.h>
#include	<string>
# include	<stdio.h>
#include	<iostream>
#include	 <fstream>
#include	"Persoana.h"
#include	"Utils.h"


using namespace std;

Persoana::Persoana()
{
	strcpy_s(this->nume, " ");
	strcpy_s(this->prenume, " ");
	strcpy_s(this->adresa, " ");
	strcpy_s(this->cnp, " ");
	strcpy_s(this->suma_asigurare, " ");
	this->incasare = new Incasari(0, 0, 0);
	this->data_nastere = new Data(0, 0, 0,0);
}

Persoana::Persoana(char nume[], char prenume[], char adresa[],char suma_asigurarem[], char cnp[], char suma_asigurare[])
{
	strcpy_s(this->nume,strlen(nume)+1,nume);
	strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
	strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	strcpy_s(this->cnp, strlen(cnp) + 1, cnp);
	strcpy_s(this->suma_asigurare, strlen(suma_asigurarem) + 1, suma_asigurarem);
	this->data_nastere = new Data(0, 0, 0, 0);
	this->incasare = new Incasari(0, 0, 0);
}

Persoana::~Persoana()
{
	cout << "A fost apelat destructorul din Persoana" << endl;
}

char *Persoana::getCNP() {
	return this->cnp;
}

char *Persoana::getSumaAsigurare()
{
	return this->suma_asigurare;
}

void Persoana::Afisare()
{
	cout << "Nume:                  " << nume << endl;
	cout << "Prenume:               " << prenume << endl;
	cout << "CNP:                   " << cnp << endl;
	cout << "Adresa:                " << adresa << endl;
	cout << "Suma asigurare anuala: " << suma_asigurare << endl;
	cout << "Incasare:              " << *incasare << endl; 
}
void Persoana::Afisare_data_nastere()
{
	cout << "Nume:                  " << nume << endl;
	cout << "Prenume:               " << prenume << endl;
	cout << "CNP:                   " << cnp << endl;
	cout << "Adresa:                " << adresa << endl;
	cout << "Suma asigurare anuala: " << suma_asigurare << endl;
	data_nastere = DataNasterii(cnp);
	cout << "Data nastere:" << *data_nastere << "\n";
	int varsta = Varsta(cnp);
	cout << "Varsta: " << varsta << endl;

}

void Persoana::Citire(FILE *file_in)
{
	char buffer[255];
	int len1 = 255;
	char *context = NULL;

	int contor = 0;
	fgets(buffer, len1, file_in);
	char *str = strtok_s(buffer, ",\n", &context);
	while (str != NULL) {


		switch (contor % 5)
		{
		case NUME:
			strcpy_s(this->nume, strlen(str) + 1, str);
			break;
		case PRENUME:
			strcpy_s(this->prenume, strlen(str) + 1, str);

			break;
		case LOCATIE:
			strcpy_s(this->adresa, strlen(str) + 1, str);
			break;
		case CNP:
			strcpy_s(this->cnp, strlen(str) + 1, str);
			break;
		case PRET:
			strcpy_s(this->suma_asigurare, strlen(str) + 1, str);
			break;
		default:
			break;
		}

		contor++;

		if (str != NULL){
			str = strtok_s(NULL, ",\n", &context);
		}

	}


}

void Persoana::modifica_date_clienti_fisier(FILE *file, FILE *file2, char nume[], double suma) {
	char buffer[255];
	int len1 = 255;
	char *context = NULL;
	char buffer_aux[255];
	int contor = 0;

	while (fgets(buffer, len1, file)) {
		strcpy_s(buffer_aux, strlen(buffer) + 1, buffer);
		char *str = strtok_s(buffer, ",\n", &context); 
		if (strcmp(str, nume) == 0) {
			printf("%s = %s \n", str, nume);
			while (str != NULL) {
				contor++;
				if (contor == 5) {
					fprintf(file2, "%lf\n", suma);					
				}
				else {
					fprintf(file2, "%s,", str);
				}

				if (str != NULL){
					str = strtok_s(NULL, ",\n", &context);
				}
			}
		}
		else {
			fprintf(file2, "%s", buffer_aux);
		}
	}

	

}



void Persoana::Suma_achitata()
{
	
	size_t dim1, dim2;
	char suma_achitata[7];
	cout << "Introduceti suma oferita de client: ";
	cin >> suma_achitata;
	dim1 = strlen(suma_achitata);
	dim2 = strlen(this->getSumaAsigurare());
	double sum_achit = stod(suma_achitata, &dim1);
	double sum_asig = stod(this->getSumaAsigurare(), &dim2);

	incasare->setSuma_Incasata(sum_achit);
	if (sum_asig - sum_achit < 0)
		incasare->setRest(sum_achit - sum_asig);
	else
		incasare->setRest(0);
	if (sum_asig - sum_achit > 0)
		incasare->setSuma_ramasa_achitat(sum_asig - sum_achit);
	else
		incasare->setSuma_ramasa_achitat(0);

	if (sum_asig == sum_achit)
	{
		cout << "Clientul a achitat intreaga suma cu succes" << endl;
	}
	cout << "Sume:"<<endl << *incasare << "\n";
}





