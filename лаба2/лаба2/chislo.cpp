#include <iostream>
#include <string>
#include "Chislo.h"

using namespace std;

//конструктор без параметров

Chislo::Chislo()

{
	mantissa = 0;
	poryadok = 0;
	strokovoepredstavlenie = "";
	cout << "Constructor for object:" << this << endl;
}

//конструктор с параметрами
Chislo::Chislo(float N, int K, string S)

{
	mantissa = N;
	poryadok = K;
	strokovoepredstavlenie = S;
	cout << "Constructor character object: " << this << endl;
}

//конструктор копирования
Chislo::Chislo(const Chislo& t)
{
	mantissa = t.mantissa;
	poryadok = t.poryadok;
	strokovoepredstavlenie = t.strokovoepredstavlenie;
	cout << "Constructor for copy object: " << this << endl;
}

//деструктор
Chislo::~Chislo()
{
	cout << "Destructor: " << this << endl;
}

//селекторы
float Chislo::get_mantissa()
{
	return mantissa;
}

int Chislo::get_poryadok()
{
	return poryadok;
}

string Chislo::get_strokovoepredstavlenie()
{
	return strokovoepredstavlenie;
}

//модификаторы
void Chislo::set_mantissa(float N)
{
	mantissa = N;
}

void Chislo::set_poryadok(int K)
{
	poryadok = K;
}

void Chislo::set_strokovoepredstavlenie(string S)
{
	strokovoepredstavlenie = S;
}

//метод для просмотра атрибутов
void Chislo::show()
{
	setlocale(LC_ALL, "Rus"); //Rus
	cout << "мантисса : " << mantissa << endl;
	cout << "порядок : " << poryadok << endl;
	cout << "строковое представление : " << strokovoepredstavlenie << endl;
}