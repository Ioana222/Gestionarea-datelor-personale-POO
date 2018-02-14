#pragma once
#include<iostream>
using std::ostream;



class Data
{
private:
	int an, luna, zi;
	int varsta;
public:
	Data();
	Data(char cnp[]);
	Data(int an, int luna, int zi, int varsta);
	~Data();
	int getAn();
	int getLuna();
	int getZi();
	int getVarsta();
	friend ostream& operator<<(ostream& output, const Data &d)
	{
		return output << d.zi << "." << d.luna << "." << d.an;
	}
	friend Data *DataNasterii(char cnp[]);
	friend int Varsta(char cnp[]);

};
