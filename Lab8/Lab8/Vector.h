#pragma once
#include "Object.h"
using namespace std;

class Vector
{
public:
	Vector(int);//����������� � �����������
	Vector();
public:
	~Vector(void);//����������
	void Add();//���������� ������ �������� � ������
	void Del();
	void Show();
	void ShowItemK(const TEvent&e);
	int operator()();//������ �������
protected:
	Object**beg;//��������� �� ������ ������� �������
	int size;//������
	int cur;//������� �������
};

