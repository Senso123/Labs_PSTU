#pragma once
struct Range
{
	float first;			//левая граница
	float second;			//правая граница
	void Init(float, float);	//инициализация объекта структуры
	void Read();			//метод для чтения полей структуры
	void Show();			//метод для вывода на экран объекта структуры
	bool rangecheck(float x);	//метод для определения принадлежности числа к диапазону
};

