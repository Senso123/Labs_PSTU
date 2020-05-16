#include <iostream>
#include "Pair.h"
#include "Complex.h"
#include <clocale>
using namespace std;

//функция принимает объект базового класса как параметр
void f1(Pair&c)
{
	c.Set_first(11);
	cout << c;
}

//функция возвращает объект базового класса как результат
Pair f2()
{
	Complex l(17, 11);
	return l;
}

void main()
{
	setlocale(LC_ALL, "russian");
	//работа с классом Pair
	Pair a;
	cin >> a;
	cout << "--a--\n";
	cout << a;
	Pair b(4, 5);
	cout << "--b--\n";
	cout << b;
	cout << "Сложение: a + b = " << a + b << endl;
	a = b;
	cout << "--a после присваивания b--\n";
	cout << a;
	//работа с классом Complex
	Complex c;
	cin >> c;
	cout << "--c--\n";
	cout << c;
	Complex d(7, 9);
	cout << "--d--\n";
	cout << d;
	//демонстрация перегрузок
	cout << "Вычитание: c - d = " << c - d << endl;
	cout << "Умножение: c * d = " << c * d << endl;

	//принцип подстановки
	cout << "\nПринцип подстановки:\n";
	f1(c);//передаем объект класса Complex
	a = f2();//создаем в функции объект класса Complex
	cout << a;
	system("pause");
}