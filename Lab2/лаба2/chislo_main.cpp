#include <iostream>
#include <string>
#include "Chislo.h"

using namespace std;
//функция для возврата объекта как результата

Chislo make_Chislo()
{
	setlocale(LC_ALL, "Rus"); //Rus

	float N;
	int K;
	string S;
	cout << "Введиде мантису: ";
	cin >> N;
	cout << "Введите порядок: ";
	cin >> K;
	cout << "введите строковое представление: ";
	cin >> S;
	Chislo t(N, K, S);
	return t;
}
//функция для передачи объекта как параметра
void print_Chislo(Chislo t)
{
	t.show();
}

int main()
{
	setlocale(LC_ALL, "Rus"); //Rus
	//конструктор без параметров
	Chislo t1;
	t1.show();
	//коструктор с параметрами
	Chislo t2(1, 1, "Тест");
	t2.show();
	//конструктор копирования
	Chislo t3 = t2;
	t3.set_mantissa(1);
	t3.set_poryadok(2);
	t3.set_strokovoepredstavlenie("Тест");
	//конструктор копирования
	print_Chislo(t3);
	//конструктор копирования
	t1 = make_Chislo();
	t1.show();
}