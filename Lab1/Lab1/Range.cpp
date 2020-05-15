#include "Range.h"
#include <iostream>		//���������� ���������� ��� ��������� �����-������
using namespace std;

//���������� ������ ��� ������������� ����� ���������
void Range::Init(float f, float s)
{
	first = f;
	second = s;
}

//���������� ������ ��� ������ ����� ���������
void Range::Read()
{
	cout << "Left (first): ";
	cin >> first;
	cout << "Right (second): ";
	cin >> second;
}

//���������� ������ ��� ������ �������� ����� ���������
void Range::Show()
{
	cout << "[" << first << "; " << second << "]" << endl;
}

//���������� ������ ��� ����������� �������������� ����� � ���������
bool Range::rangecheck(float x)
{
	bool rez;
	if (x >= first && x <= second)
		rez = true;
	else rez = false;
	return rez;
}
