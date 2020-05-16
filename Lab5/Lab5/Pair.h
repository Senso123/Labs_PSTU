#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Pair :
	public Object
{
	//��������
protected:
	int first;
	int second;
public:
	Pair(void); //����������� ��� ����������
	virtual ~Pair(void); //����������
	Pair(int, int); //����������� � �����������
	Pair(const Pair&); //����������� �����������
					   //���������
	int Get_first() { return first; }
	int Get_second() { return second; }
	//������������
	void Set_first(int);
	void Set_second(int);
	//���������� �������� ������������
	Pair& operator=(const Pair&);
	//���������� �������� ��������
	Pair operator+(const Pair&);
	//���������� ���������-������� �����-������
	friend istream& operator >> (istream&in, Pair&p);
	friend ostream& operator<<(ostream&out, const Pair&p);
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������
};

