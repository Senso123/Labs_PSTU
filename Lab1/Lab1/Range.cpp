#include "Range.h"
#include <iostream>		//подключаем бибилотеку дл€ поточного ввода-вывода
using namespace std;

//реализаци€ метода дл€ инициализации полей структуры
void Range::Init(float f, float s)
{
	first = f;
	second = s;
}

//реализаци€ метода дл€ чтени€ полей структуры
void Range::Read()
{
	cout << "Left (first): ";
	cin >> first;
	cout << "Right (second): ";
	cin >> second;
}

//реализаци€ метода дл€ вывода значений полей структуры
void Range::Show()
{
	cout << "[" << first << "; " << second << "]" << endl;
}

//реализаци€ метода дл€ определени€ принадлежности числа к диапазону
bool Range::rangecheck(float x)
{
	bool rez;
	if (x >= first && x <= second)
		rez = true;
	else rez = false;
	return rez;
}
