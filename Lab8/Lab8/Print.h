#pragma once
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;

class Print :
	public Object
{
public:
	Print(void);//конструктор без параметров
public:
	virtual ~Print(void);//деструктор
	void Show();//функция для просмотра атрибутов класса с помощью указателя
	void Input();//функция для ввода значений атрибутов
	Print(string, string);//конструктор с параметрами
	Print(const Print&);//конструктор копирования
	//селекторы
	string Get_name(){ return name; }
	string Get_autor(){ return autor; }
	//модификаторы
	void Set_name(string);
	void Set_autor(string);
	Print& operator=(const Print&);//перегрузка операции присваивания
	virtual void HandleEvent(const TEvent&e);
protected:
	string name;
	string autor;
};

