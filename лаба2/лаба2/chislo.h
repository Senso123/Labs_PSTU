#pragma once
#include <iostream>
#include <string>

using namespace std;

class Chislo
{
	//атрибуты
	float mantissa;
	int poryadok;
	string strokovoepredstavlenie;

public:

	Chislo();						//конструктор без параметров
	Chislo(float, int, string);		//конструктор с параметрами
	Chislo(const Chislo&);			//конструктор копирования
	~Chislo();						//деструктор

	float get_mantissa();						//селектор
	void set_mantissa(float);					//модификатор
	int get_poryadok();							//селектор
	void set_poryadok(int);						//модификатор
	string get_strokovoepredstavlenie();		//селектор
	void set_strokovoepredstavlenie(string);	//модификатор
	void show();								//просмотр атрибутов
};
