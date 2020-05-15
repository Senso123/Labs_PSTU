#include "Complex.h"
//����������� ��� ���������� ����������� �� ������ �� ������������ � ������������ ������
Complex::Complex(void) : Pair()
{
}

//����������
Complex::~Complex()
{
}

//����������� � ����������� ����������� �� ������ �� � �����. ������, 
//�.�. �� ����� ����� ��������� ���� ��������
Complex::Complex(int c, int d) : Pair(c, d)
{
}

//����������� �����������
Complex::Complex(const Complex &f) : Pair(f)
{
}

//������� ������������
Complex& Complex::operator=(const Complex& f)
{
	if (&f == this)
		return *this;
	first = f.first;
	second = f.second;
	return *this;
}

//�������� �����
istream& operator >> (istream&in, Complex& f)
{
	cout << "\n�������������� �����: "; in >> f.first;
	cout << "\n������ �����: "; in >> f.second;
	return in;
}
//�������� ������
ostream& operator<<(ostream&out, const Complex& f)
{
	out <<  f.first << " + " << f.second << "i" << endl;
	return out;
}

//���������� ��������� ���������
Complex Complex::operator*(const Complex&f)
{
	Complex rez;
	rez.first = first * f.first - second  *f.second;
	rez.second = first * f.second + second * f.first;
	return rez;
}

//���������� ��������� ���������
Complex Complex::operator-(const Complex&f)
{
	Complex rez;
	rez.first = first - f.first;
	rez.second = second - f.second;
	return rez;
}