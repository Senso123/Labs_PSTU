#include "Pair.h"

//конструктор без параметров
Pair::Pair(void)
{
	first = 0;
	second = 0;
}

//деструктор
Pair::~Pair(void)
{
}

//конструктор с параметрами
Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}

//конструктор копирования
Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

//модификаторы
void Pair::Set_first(int f)
{
	first = f;
}
void Pair::Set_second(int s)
{
	second = s;
}

//перегрузка операции присваивания
Pair& Pair::operator=(const Pair&p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}
//глобальная функция для ввода
istream& operator >> (istream&in, Pair&p)
{
	cout << "First: "; in >> p.first;
	cout << "\nSecond: "; in >> p.second;
	return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream&out, const Pair&p)
{
	out << "(" << p.first << ", " << p.second << ")" << endl;
	return out;
}

//перегрузка оператора сложения
Pair Pair::operator+(const Pair& p)
{
	Pair rez;
	rez.first = first + p.first;
	rez.second = second + p.second;
	return rez;
}

//функция для просмотра атрибутов класса с помощью указателя
void Pair::Show()
{
	cout << "FIRST: " << first;
	cout << "\nSECOND: " << second;
	cout << "\n\n";
}
