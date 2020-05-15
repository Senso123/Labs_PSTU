#pragma once
#include "Pair.h"
class Complex :
	public Pair
{
public:
public:
	Complex(void); //����������� ��� ����������
public:
	~Complex(); //����������
	Complex(int, int); //����������� � �����������
	Complex(const Complex&); //����������� �����������
	Complex& operator=(const Complex&); //�������� ������������
	friend istream& operator >> (istream&in, Complex &f);//�������� �����
	friend ostream& operator<<(ostream&out, const Complex &f); //�������� ������
	//���������� �������� ��������� � ���������
	Complex operator*(const Complex&);
	Complex operator-(const Complex&);
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������
};

