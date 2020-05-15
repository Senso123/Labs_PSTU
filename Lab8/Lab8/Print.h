#pragma once
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;

class Print :
	public Object
{
public:
	Print(void);//����������� ��� ����������
public:
	virtual ~Print(void);//����������
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������
	void Input();//������� ��� ����� �������� ���������
	Print(string, string);//����������� � �����������
	Print(const Print&);//����������� �����������
	//���������
	string Get_name(){ return name; }
	string Get_autor(){ return autor; }
	//������������
	void Set_name(string);
	void Set_autor(string);
	Print& operator=(const Print&);//���������� �������� ������������
	virtual void HandleEvent(const TEvent&e);
protected:
	string name;
	string autor;
};

