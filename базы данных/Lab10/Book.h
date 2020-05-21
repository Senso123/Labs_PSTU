#pragma once
#include <iostream>
using namespace std;

struct book
{
	int key; //личный ключ записи
	char autor[50]; //автор
	char title[50];	//название
	int year; //год издания
	char publishing[50]; //издательство
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
	cout << "Уникальный ключ книги: ";
	cin >> b.key;
	cout << "Автор: ";
	cin >> b.autor;
	cout << "Название: ";
	cin >> b.title;
	cout << "Год издания: ";
	cin >> b.year;
	cout << "Издательство: ";
	cin >> b.publishing;
	return b;
}

void showBook(book b)
{
	cout << "Уникальный ключ книги: " << b.key << endl;
	cout << "Автор: " << b.autor << endl;
	cout << "Название: " << b.title << endl;
	cout << "Год издания: " << b.year << endl;
	cout << "Издательство: " << b.publishing << endl;
}