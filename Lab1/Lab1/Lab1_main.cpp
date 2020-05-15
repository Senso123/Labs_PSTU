#include <iostream>
#include "Range.h"
using namespace std;

Range makeRange(float f, float s)
{
	Range t;		//создали временную переменную
	t.Init(f, s);	//инициализировали поля переменной с помощью параметров функции
	return t;		//вернули значение переменной t
}

void main()
{
	setlocale(LC_ALL, "russian");
	//определение переменных А и В
	cout << "------Переменные------" << endl;
	Range A;
	Range B;
	A.Init(2.9, 5.3);	//инициализация переменной А
	B.Read();		//ввод полей переменных В
	cout << "A: ";
	A.Show();		//вывод значений полей переменной А
	cout << "B: ";
	B.Show();		//вывод значений полей переменной В
	//вывод целой части дроби, вычисленной с помощью функции ipart()
	cout << "A.rangecheck(10.4) = " << A.rangecheck(10.4) << endl;
	cout << "B.rangecheck(3.1) = " << B.rangecheck(3.1) << endl;

	//указатели
	cout << "\n------Указатели------" << endl;
	Range *c = new Range;	//выделение памяти под динамическую переменную
	c->Init(7.4, 12.6);	//инициализация
	cout << "C: ";
	c->Show();	//вывод значений полей
	cout << "C.rangecheck(5.1) = " << c->rangecheck(5.1) << endl;

	//массивы
	cout << "\n------Массивы------" << endl;
	Range mas[3];//определение массива
	for (int i = 0; i < 3; i++)
		mas[i].Read();//чтение значений полей
	for (int i = 0; i < 3; i++)
		mas[i].Show(); //вывод значений полей
	for (int i = 0; i < 3; i++)
		cout << "mas[" << i << "].rangecheck(3.0) = " << mas[i].rangecheck(3.0) << endl;

	//динамические масивы
	cout << "\n------Динамические массивы------" << endl;
	Range* p_mas = new Range[3];//выделение памяти
	for (int i = 0; i < 3; i++)
		p_mas[i].Read();//чтение значений полей
	for (int i = 0; i < 3; i++)
		p_mas[i].Show();//вывод значений полей
	for (int i = 0; i < 3; i++)
		cout << "p_mas[" << i << "].rangecheck(3.0) = " << p_mas[i].rangecheck(3.0) << endl;

	//вызов функции makeFraction()
	cout << "\n------Вызов функции makeRange()------" << endl;
	int y;
	int z;
	cout << "First: ";
	cin >> y;
	cout << "Second: ";
	cin >> z;
	//переменная F формируется с помощью функции makeRange()
	Range F = makeRange(y, z);
	F.Show();
	system("pause");
}