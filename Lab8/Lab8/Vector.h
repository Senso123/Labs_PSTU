#pragma once
#include "Object.h"
using namespace std;

class Vector
{
public:
	Vector(int);//конструктор с параметрами
	Vector();
public:
	~Vector(void);//деструктор
	void Add();//добавление нового элемента в вектор
	void Del();
	void Show();
	void ShowItemK(const TEvent&e);
	int operator()();//размер вектора
protected:
	Object**beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};

