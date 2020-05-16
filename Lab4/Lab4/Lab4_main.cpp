#include <iostream>
#include "Pair.h"
#include "Complex.h"
#include <clocale>
using namespace std;

//������� ��������� ������ �������� ������ ��� ��������
void f1(Pair&c)
{
	c.Set_first(11);
	cout << c;
}

//������� ���������� ������ �������� ������ ��� ���������
Pair f2()
{
	Complex l(17, 11);
	return l;
}

void main()
{
	setlocale(LC_ALL, "russian");
	//������ � ������� Pair
	Pair a;
	cin >> a;
	cout << "--a--\n";
	cout << a;
	Pair b(4, 5);
	cout << "--b--\n";
	cout << b;
	cout << "��������: a + b = " << a + b << endl;
	a = b;
	cout << "--a ����� ������������ b--\n";
	cout << a;
	//������ � ������� Complex
	Complex c;
	cin >> c;
	cout << "--c--\n";
	cout << c;
	Complex d(7, 9);
	cout << "--d--\n";
	cout << d;
	//������������ ����������
	cout << "���������: c - d = " << c - d << endl;
	cout << "���������: c * d = " << c * d << endl;

	//������� �����������
	cout << "\n������� �����������:\n";
	f1(c);//�������� ������ ������ Complex
	a = f2();//������� � ������� ������ ������ Complex
	cout << a;
	system("pause");
}