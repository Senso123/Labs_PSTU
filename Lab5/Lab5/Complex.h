#pragma once
#include "Pair.h"
class Complex :
	public Pair
{
public:
public:
	Complex(void); //конструктор без параметров
public:
	~Complex(); //деструктор
	Complex(int, int); //конструктор с параметрами
	Complex(const Complex&); //конструктор копирования
	Complex& operator=(const Complex&); //операция присваивания
	friend istream& operator >> (istream&in, Complex &f);//операция ввода
	friend ostream& operator<<(ostream&out, const Complex &f); //операция вывода
	//перегрузка операций умножения и вычитания
	Complex operator*(const Complex&);
	Complex operator-(const Complex&);
	void Show();//функция для просмотра атрибутов класса с помощью указателя
};

