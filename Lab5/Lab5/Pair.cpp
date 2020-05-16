#include "Pair.h"

//����������� ��� ����������
Pair::Pair(void)
{
	first = 0;
	second = 0;
}

//����������
Pair::~Pair(void)
{
}

//����������� � �����������
Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}

//����������� �����������
Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

//������������
void Pair::Set_first(int f)
{
	first = f;
}
void Pair::Set_second(int s)
{
	second = s;
}

//���������� �������� ������������
Pair& Pair::operator=(const Pair&p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}
//���������� ������� ��� �����
istream& operator >> (istream&in, Pair&p)
{
	cout << "First: "; in >> p.first;
	cout << "\nSecond: "; in >> p.second;
	return in;
}
//���������� ������� ��� ������
ostream& operator<<(ostream&out, const Pair&p)
{
	out << "(" << p.first << ", " << p.second << ")" << endl;
	return out;
}

//���������� ��������� ��������
Pair Pair::operator+(const Pair& p)
{
	Pair rez;
	rez.first = first + p.first;
	rez.second = second + p.second;
	return rez;
}

//������� ��� ��������� ��������� ������ � ������� ���������
void Pair::Show()
{
	cout << "FIRST: " << first;
	cout << "\nSECOND: " << second;
	cout << "\n\n";
}
