#include <iostream>
#include <string>
#include "Chislo.h"

using namespace std;

//����������� ��� ����������

Chislo::Chislo()

{
	mantissa = 0;
	poryadok = 0;
	strokovoepredstavlenie = "";
	cout << "Constructor for object:" << this << endl;
}

//����������� � �����������
Chislo::Chislo(float N, int K, string S)

{
	mantissa = N;
	poryadok = K;
	strokovoepredstavlenie = S;
	cout << "Constructor character object: " << this << endl;
}

//����������� �����������
Chislo::Chislo(const Chislo& t)
{
	mantissa = t.mantissa;
	poryadok = t.poryadok;
	strokovoepredstavlenie = t.strokovoepredstavlenie;
	cout << "Constructor for copy object: " << this << endl;
}

//����������
Chislo::~Chislo()
{
	cout << "Destructor: " << this << endl;
}

//���������
float Chislo::get_mantissa()
{
	return mantissa;
}

int Chislo::get_poryadok()
{
	return poryadok;
}

string Chislo::get_strokovoepredstavlenie()
{
	return strokovoepredstavlenie;
}

//������������
void Chislo::set_mantissa(float N)
{
	mantissa = N;
}

void Chislo::set_poryadok(int K)
{
	poryadok = K;
}

void Chislo::set_strokovoepredstavlenie(string S)
{
	strokovoepredstavlenie = S;
}

//����� ��� ��������� ���������
void Chislo::show()
{
	setlocale(LC_ALL, "Rus"); //Rus
	cout << "�������� : " << mantissa << endl;
	cout << "������� : " << poryadok << endl;
	cout << "��������� ������������� : " << strokovoepredstavlenie << endl;
}