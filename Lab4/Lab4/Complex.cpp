#include "Complex.h"
//конструктор без параметров наследуется от такого же конструктора в родительском классе
Complex::Complex(void) : Pair()
{
}

//деструктор
Complex::~Complex()
{
}

//конструктор с параметрами наследуется от такого же в родит. классе, 
//т.к. не имеет смысл создавать свои атрибуты
Complex::Complex(int c, int d) : Pair(c, d)
{
}

//конструктор копирования
Complex::Complex(const Complex &f) : Pair(f)
{
}

//оперция присваивания
Complex& Complex::operator=(const Complex& f)
{
	if (&f == this)
		return *this;
	first = f.first;
	second = f.second;
	return *this;
}

//операция ввода
istream& operator >> (istream&in, Complex& f)
{
	cout << "\nДействительная часть: "; in >> f.first;
	cout << "\nМнимая часть: "; in >> f.second;
	return in;
}
//операция вывода
ostream& operator<<(ostream&out, const Complex& f)
{
	out <<  f.first << " + " << f.second << "i" << endl;
	return out;
}

//перегрузка оператора умножения
Complex Complex::operator*(const Complex&f)
{
	Complex rez;
	rez.first = first * f.first - second  *f.second;
	rez.second = first * f.second + second * f.first;
	return rez;
}

//перегрузка оператора вычитания
Complex Complex::operator-(const Complex&f)
{
	Complex rez;
	rez.first = first - f.first;
	rez.second = second - f.second;
	return rez;
}