#include	 "Lista.h"
#include	"Tratamente.h"

List *prim = NULL;
void adauga(Tratamente *x)
{
	List *aux = NULL;
	List *p;
	aux = new List;
	(*aux).data = new Tratamente(*x); 
	(*aux).urm = 0;
	if (prim == 0) prim = aux;
	else 
	{
		for (p = prim; p && (*p).urm != NULL; p = (*p).urm);
		(*p).urm = aux;
	}
}
void show_list()
{
	List *p;
	for (p = prim; p != NULL; p = (*p).urm)
	{
		p->data->Afisare();
	}
	cout << endl;
}