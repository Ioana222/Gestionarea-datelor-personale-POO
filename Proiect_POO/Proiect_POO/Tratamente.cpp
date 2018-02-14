#include <stdio.h>
#include <iostream>
#include "Tratamente.h"
#include "Persoana.h"
#include	"Utils2.h"

using namespace std;

Tratamente::Tratamente()
{
	strcpy_s(this->boli, " ");
	strcpy_s(this->tratamente, " ");
}

Tratamente::Tratamente(char boli[], char tratamente[])
{
	strcpy_s(this->boli, boli);
	strcpy_s(this->tratamente, boli);

}
Tratamente::~Tratamente()
{
	cout << "A fost apelat destructorul din clasa Tratamente.h." << endl;
}
char *Tratamente::GetBoli()
{
	return boli;
}
char *Tratamente::GetTratamente()
{
	return tratamente;
}

void Tratamente::Afisare()
{

	
	cout << "Boli suferite:       " << boli << endl;
	cout << "Tratamente aplicate: " << tratamente << endl;

}
void Tratamente::Citire(FILE *file_boli_tratamente)
{
	char buffer[255];
	int len1 = 255;
	char *context = NULL;

	int contor = 0;
	fgets(buffer, len1, file_boli_tratamente);
	char *str = strtok_s(buffer, ",\n", &context);
	while (str != NULL) {


		switch (contor % 5)
		{
		case BOLI:
			strcpy_s(this->boli, strlen(str) + 1, str);
			break;
		case TRATAMENTE:
			strcpy_s(this->tratamente, strlen(str) + 1, str);

			break;
		}

		contor++;

		if (str != NULL){
			str = strtok_s(NULL, ",\n", &context);
		}

	}
}
void Tratamente::Citire()
{
char buffer[255];
char buffer2[225];
int len1 = 255;
int len2 = 225;
char *context = NULL;
char *context2 = NULL;

fflush(stdin);
cout << "Introduceti noua boala: ";
cin.getline(buffer, len1);
cout << "Introduceti noul tratament: ";
cin.getline(buffer2, len2);
char *str = strtok_s(buffer, ",\n", &context);
char *str2 = strtok_s(buffer2, ",\n", &context2);
strcpy_s(this->boli, strlen(str) + 1, str);
strcpy_s(this->tratamente, strlen(str2) + 1, str2);

	if (str != NULL){
		str = strtok_s(NULL, ",\n", &context);
	}
	if (str2 != NULL){
		str2 = strtok_s(NULL, ",\n", &context2);
	}

}
