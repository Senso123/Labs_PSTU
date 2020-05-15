#pragma once
#include <string>
#include <iostream>
#include "Vector.h"
#include "Print.h"
#include "Book.h"
using namespace std;

//деструктор
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

Vector::Vector()
{
	beg = 0;
	cur = 0;
	size = 0;
}

//конструктор с параметрами
Vector::Vector(int n)
{
	beg = new Object*[n];
	cur = 0;
	size = n;
}

//добавление нового объекта в вектор
void Vector::Add()
{
	Object*p;
	//выбор из объектов двух возможных классов
	cout << "1. Print" << endl;
	cout << "2. Book" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Print
	{
		Print* a = new Print;
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Book
		{
			Book *b = new Book;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}

//просмотр вектора
void Vector::Show()
{
	if (cur == 0) 
		cout << "Пусто" << endl;
	Object **p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}
}
//операция, которая возвращает размер вектора
int Vector::operator ()()
{
	return cur;
}

//удаление элемента из вектора, память не освобождается!
void Vector::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}

void Vector::ShowItemK(const TEvent&e)
{
	if (e.a > size)
	{
		cout << "Такого элемента в группе нет!" << endl;
		return;
	}
	Object**p = beg;
	//сначала добираемся до нужного элемента 
	for (int i = 1; i <= e.a; i++)
		p++;//передвигаем указатель на следующий объект
	//затем отображаем инфу об элементе
	(*p)->HandleEvent(e);//вызов метода (позднее связывание)
}