#include "Vector.h"
#include <ctime>

Vector::Vector(int s)
{
	srand(time(0)); // автоматическая рандомизация
	//если текущий размер больше максимального, то генерируется исключение
	if (s > MAX_SIZE)
		throw 1;
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = rand() % 100 + 1;
}
Vector::Vector(const Vector &v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}
Vector::~Vector()
{
	if (beg != 0)
		delete[]beg;
}
Vector::Vector(int s, int *mas)
{
	//если текущий размер больше максимального, то генерируется исключение
	if (s > MAX_SIZE)
		throw 1;
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}
const Vector& Vector::operator =(const Vector &v)
{
	if (this == &v)
		return *this;
	if (beg != 0)
		delete[]beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return*this;
}

ostream& operator<<(ostream&out, const Vector&v)
{
	if (v.size == 0)
		out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator >>(istream&in, Vector&v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}
int Vector::operator [](int i)
{
	if (i < 0)
		throw 2;//если индекс отрицательный, то генерируется исключение
	//если индекс больше размер вектора, то генерируется исключение
	if (i >= size)
		throw "Vector length more than MAXSIZE\n";
	return beg[i];
}

//постфиксный декремент - удаление из конца
Vector Vector::operator--(int)
{
	//если размер вектора равен 0, то генерируется исключение
	if (size == 0)
		throw 4;
	if (size == 1)
	{
		size = 0;
		return *this;
	}
	Vector temp(size, beg);    //Логика этого метода: создается новый вектор (копия)
	delete[]beg;				// удаляется вектор, с которым работаем (в нашем случае х)
	size = size - 1;				// вычисляется новый размер
	beg = new int[size];		//создается новый вектор по новому размеру
	for (int i = 0; i < size; i++)	//и в цикле новому вектору присваиваем значения элементов вектора, кроме последнего
		beg[i] = temp.beg[i];
	return*this;
}
//префиксный декремент - удаление из начала
Vector Vector::operator--()
{
	//если размер вектора равен 0, то генерируется исключение
	if (size == 0)
		throw 4;
	if (size == 1)
	{
		size = 0;
		delete[]beg;
		return *this;
	}
	Vector temp(size, beg);    //Логика этого метода: создается новый вектор (копия)
	delete[]beg;				// удаляется вектор, с которым работаем (в нашем случае х)
	size = size - 1;				// вычисляется новый размер
	beg = new int[size];		//создается новый вектор по новому размеру
	for (int i = 1; i < size + 1; i++)	//и в цикле новому вектору присваиваем значения элементов вектора, кроме первого
		beg[i-1] = temp.beg[i];
	return*this;
}

int Vector::operator()()
{
	return size;
}
