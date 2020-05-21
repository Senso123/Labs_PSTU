#pragma once
#include <iostream>
using namespace std;

struct book
{
	int key; //������ ���� ������
	char autor[50]; //�����
	char title[50];	//��������
	int year; //��� �������
	char publishing[50]; //������������
};

bool isEqual(book a, book b)
{
	bool eq;
	if (a.key == b.key && strcmp(a.autor, b.autor) == 0 && strcmp(a.title, b.title) == 0 &&
		a.year == b.year && strcmp(a.publishing, b.publishing) == 0)
		eq = true;
	else
		eq = false;
	return eq;
}

book createBook()
{
	book b;
	cout << "���������� ���� �����: ";
	cin >> b.key;
	cout << "�����: ";
	cin >> b.autor;
	cout << "��������: ";
	cin >> b.title;
	cout << "��� �������: ";
	cin >> b.year;
	cout << "������������: ";
	cin >> b.publishing;
	return b;
}

void showBook(book b)
{
	cout << "���������� ���� �����: " << b.key << endl;
	cout << "�����: " << b.autor << endl;
	cout << "��������: " << b.title << endl;
	cout << "��� �������: " << b.year << endl;
	cout << "������������: " << b.publishing << endl;
}