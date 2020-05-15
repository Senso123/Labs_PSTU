#include <iostream>
#include <string>
#include "Chislo.h"

using namespace std;
//������� ��� �������� ������� ��� ����������

Chislo make_Chislo()
{
	setlocale(LC_ALL, "Rus"); //Rus

	float s;
	int i;
	string d;
	cout << "������� �������: ";
	cin >> s;
	cout << "������� �������: ";
	cin >> i;
	cout << "������� ��������� �������������: ";
	cin >> d;
	Chislo t(s, i, d);
	return t;
}
//������� ��� �������� ������� ��� ���������
void print_Chislo(Chislo t)
{
	t.show();
}

int main()
{
	setlocale(LC_ALL, "Rus"); //Rus
	//����������� ��� ����������
	Chislo t1;
	t1.show();
	//���������� � �����������
	Chislo t2(1, 1, "����");
	t2.show();
	//����������� �����������
	Chislo t3 = t2;
	t3.set_mantissa(1);
	t3.set_poryadok(2);
	t3.set_strokovoepredstavlenie("����");
	//����������� �����������
	print_Chislo(t3);
	//����������� �����������
	t1 = make_Chislo();
	t1.show();
}