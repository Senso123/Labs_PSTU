#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Pair :
	public Object
{
	//атрибуты
protected:
	int first;
	int second;
public:
	Pair(void); //конструктор без параметров
	virtual ~Pair(void); //деструктор
	Pair(int, int); //конструктор с параметрами
	Pair(const Pair&); //конструктор копирования
					   //селекторы
	int Get_first() { return first; }
	int Get_second() { return second; }
	//модификаторы
	void Set_first(int);
	void Set_second(int);
	//перегрузка операции присваивания
	Pair& operator=(const Pair&);
	//перегрузка операцит сложения
	Pair operator+(const Pair&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator >> (istream&in, Pair&p);
	friend ostream& operator<<(ostream&out, const Pair&p);
	void Show();//функция для просмотра атрибутов класса с помощью указателя
};

