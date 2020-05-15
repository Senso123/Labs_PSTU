#pragma once
#include <iostream>
#include <ctime>
using namespace std;

struct point
{
	int data;	//�������������� ����
	point* next;	//�������� ����
};

//�������� ����������������� ������
//���������� � �����
point* make_list(int n)
{
	srand(time(0)); // �������������� ������������
	point*beg;	//��������� �� ������ �������
	point*p, *r;	//��������������� ���������
	beg = new(point);	//�������� ������ ��� ������ �������
	beg->data = rand() % 100 + 1;	//��������� �������� ��������������� ����
	beg->next = 0;	//�������� �������� ����
	p = beg;	//������ �� ���� ������� ��������� p (��������� �������)
	for (int i = 0; i < n - 1; i++)
	{
		r = new(point);	//������� ����� �������
		r->data = rand() % 100 + 1;
		r->next = 0;
		p->next = r;	//��������� p � r
		p = r;	//������ �� r ��������� p (��������� �������)
	}
	return beg;	//���������� beg ��� ��������� �������
}

//������ ������
void print_list(point* beg)
{
	if(beg == 0)
		cout << "������ ����!" << endl;
	point* p = beg;//������ ������
	while (p != 0)
	{
		cout << p->data << " ";
		p = p->next;//������� � ���������� ��������
	}
	cout << endl;
}

//�������� �������� � ������� k �� ������
point* del_point(point*beg, int k)
{
	point*p = beg;
	if (k == 0)//�������� ������� ��������
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//�������� �� ������ �� �������� � ������� k-1
	for (int i = 1; i < k && p->next != 0; i++)
		p = p->next;
	/*���� ������ �������� � ������ ���, �� ���������� ��������� �� ������ ������ � �������� ���������� �������*/
	if (p->next == 0) 
		return beg;
	point* r = p->next;//������ ��������� r �� k-� �������
	p->next = r->next;//��������� k-1 � k+1 �������
	delete r;//������� k-� ������� �� ������
	return beg;
}

//������� ��� ������ �� �������
point* task_for_list(point *beg)
{
	point *p = beg;
	//���� ����� �������� ��� ��������
	int pos = -1;
	int k = 0; //������� ������� ���������
	while (p != 0)
	{
		if (p->data % 2 == 0)
			pos = k;
		p = p->next;//������� � ���������� ��������
		k++;
	}
	point* rez = beg;
	if (k == -1)
		cout << "������ ������� ��� �������� �� ������!" << endl;
	else
		rez = del_point(beg, pos);
	return rez;
}

//������� ������
point* clear_list(point*beg)
{
	point *p = beg;
	while (p->next)
	{
		point* tmp;
		tmp = p;
		p = p->next;
		delete tmp;
	}
	p = p->next;
	delete[]p;
	p = NULL;
	return p;
}

