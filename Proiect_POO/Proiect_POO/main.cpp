#include	<string.h>
#include	<conio.h>
#include	<iostream>
#include	 <fstream>
#include	"Lista.h"

using namespace std;
int main()
{
	FILE *file_in = NULL;
	fopen_s(&file_in, "date_clienti.txt", "r");
	FILE *file_tratamente = NULL;
	fopen_s(&file_tratamente, "boli_tratamente.txt", "r");
	int numar_clienti;
	int enter;
	fscanf_s(file_in, "%d", &numar_clienti);
	fscanf_s(file_in, "%d", &enter);

	Persoana *m = new Persoana[100];
	Tratamente *p = new Tratamente[100];
	Tratamente z;
	

	int aux = 0;
	int nr = 0;
	int variabila = 0;
	int key = 'h';
	do
	{
		switch (key)
		{


		case 'c':
		{
					system("CLS");
					break;
		}
		case 'h':
		{
					cout << "---MENIU:---" << endl;
					cout << "h- Meniu" << endl;
					cout << "c- Sterge consola" << endl;
					cout << "0- Citire date din fisier" << endl;
					cout << "1- Afisare date din fisier" << endl;
					cout << "2- Determinare data nastere dupa CNP si varsta" << endl;
					cout << "3- Cautare persoana dupa CNP" << endl;
					cout << "4- Deterinare rest/suma ramasa" << endl;
					cout << "5- Afisarea bolilor si a tratamentelor suferite de persoana cautata" << endl;
					cout << "6- Introduceti o noua boala si un nou tratament pentru persoana" << endl;
					cout << "esc- Exit" << endl;
					break;
		}

		case '0':
		{
					for (int i = 0; i < numar_clienti; i++)
					{
						m[i].Citire(file_in);

					}
					for (int i = 0; i < numar_clienti; i++)
					{
						p[i].Citire(file_tratamente);

					}
					cout << "S-a realizat citirea din fisier. Puteti realiza operatiile dorite" << endl;
					fclose(file_tratamente);
					fclose(file_in);
					break;
		}
		case '1':
		{
					for (int i = 0; i < numar_clienti; i++)
					{
						m[i].Afisare();
						cout << endl;
					}
					break;
		}
		case '2':
		{
					int varsta;
					for (int i = 0; i < numar_clienti; i++)
					{
						m[i].Afisare_data_nastere();
						cout << endl;
					}
					break;
		}
		case '3':
		{
					cout << endl << "Introduceti CNP=ul clientului: ";
					char c[14];
					cin >> c;
					for (int i = 0; i < numar_clienti; i++)
					{
						if (strcmp(c, m[i].getCNP()) == 0)
						{
							m[i].Afisare();
							aux = i;
							nr = nr + 1;
							break;
						}
					}
					if (nr == 0)
					{
						cout << "----->>>>CNP-ul introdus este gresit sau inexistent" << endl;
						cout << "--->> Reapasati tasta 3 pentru reintroducerea CNP-ului" << endl;
					}
					break;
		}
		case '4':
		{
					FILE *file_in_2 = NULL;
					FILE *f_write = NULL;
					m[aux].Suma_achitata();
	
					fopen_s(&file_in_2, "test.txt", "r");
					fopen_s(&f_write, "test_copy.txt", "w");

					m[aux].modifica_date_clienti_fisier(file_in_2, f_write, m[aux].getNume(), 1000);

					fclose(file_in_2);
					fclose(f_write);
					break;
		}
		case '5':
		{
					p[aux].Afisare();
					break;
		}
		case '6':
		{
					z.Citire();
					cout << endl;
					adauga(&z);
					show_list();
					break;
		}
		}
		cout << endl << "--->>> ";
		key = _getche();
		cout << endl;
	} while (key != 27);
	_getch();
	return 0;
}