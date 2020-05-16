#pragma once
#include <iostream>
#include <string>

using namespace std;

class Chislo
{
	//��������
	float mantissa;
	int poryadok;
	string strokovoepredstavlenie;

public:

	Chislo();						//����������� ��� ����������
	Chislo(float, int, string);		//����������� � �����������
	Chislo(const Chislo&);			//����������� �����������
	~Chislo();						//����������

	float get_mantissa();						//��������
	void set_mantissa(float);					//�����������
	int get_poryadok();							//��������
	void set_poryadok(int);						//�����������
	string get_strokovoepredstavlenie();		//��������
	void set_strokovoepredstavlenie(string);	//�����������
	void show();								//�������� ���������
};
