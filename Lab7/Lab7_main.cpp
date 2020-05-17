#include <iostream>
#include "Vector.h"
#include"Time.h"
#include<string>


using namespace std;
int main()
{

	//инициализация, ввод и вывод значений вектора
	Vector<int>A(5, 0);
	cin >> A;
	cout << A << endl;
	//инициализация и вывод значений вектора
	Vector <int>B(10, 1);
	cout << B << endl;
	//операция присваивания
	B = A;
	cout << B << endl;
	//доступ по индексу
	cout << A[2] << endl;
	//получение длины вектора
	cout << "size=" << A() << endl;
	//операция сложения с константой
	B = A + 10;
	cout << B << endl;

}