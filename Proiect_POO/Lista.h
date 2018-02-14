#pragma once
#include <iostream>
#include "Tratamente.h"
using namespace std;

struct List
{
	Tratamente *data;
	List* urm;
};

void adauga(Tratamente *x);
void show_list();