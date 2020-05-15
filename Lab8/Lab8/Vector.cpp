#pragma once
#include <string>
#include <iostream>
#include "Vector.h"
#include "Print.h"
#include "Book.h"
using namespace std;

//����������
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

Vector::Vector()
{
	beg = 0;
	cur = 0;
	size = 0;
}

//����������� � �����������
Vector::Vector(int n)
{
	beg = new Object*[n];
	cur = 0;
	size = n;
}

//���������� ������ ������� � ������
void Vector::Add()
{
	Object*p;
	//����� �� �������� ���� ��������� �������
	cout << "1. Print" << endl;
	cout << "2. Book" << endl;
	int y;
	cin >> y;
	if (y == 1)//���������� ������� ������ Print
	{
		Print* a = new Print;
		a->Input();//���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � ������
			cur++;
		}
	}
	else
		if (y == 2) //���������� ������� ������ Book
		{
			Book *b = new Book;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}

//�������� �������
void Vector::Show()
{
	if (cur == 0) 
		cout << "�����" << endl;
	Object **p = beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������
	}
}
//��������, ������� ���������� ������ �������
int Vector::operator ()()
{
	return cur;
}

//�������� �������� �� �������, ������ �� �������������!
void Vector::Del()
{
	if (cur == 0)return;//������
	cur--;
}

void Vector::ShowItemK(const TEvent&e)
{
	if (e.a > size)
	{
		cout << "������ �������� � ������ ���!" << endl;
		return;
	}
	Object**p = beg;
	//������� ���������� �� ������� �������� 
	for (int i = 1; i <= e.a; i++)
		p++;//����������� ��������� �� ��������� ������
	//����� ���������� ���� �� ��������
	(*p)->HandleEvent(e);//����� ������ (������� ����������)
}