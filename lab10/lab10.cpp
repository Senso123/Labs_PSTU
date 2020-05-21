#include "Time.h"
#include "file_work.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Time t1;
	int k, c;
	char file_name[30];
	do
	{
		cout << "1. Создать файл" << endl;
		cout << "2. Вывести содержимое файла" << endl;
		cout << "3. Удалить все записи из интервала от k1 до k2" << endl;
		cout << "4. Увеличить все записи с заданым значением на 1:30" << endl;
		cout << "5. Добавить записи в начало файла" << endl;
		cout << "0. Exit" << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Введите имя файла" << endl;
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)
				cout << "Невозможно создать файл";
			break;
		case 2:
			cout << "Введите имя файла" << endl;
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0)
				cout << "Файл пуст" << endl;
			if (k < 0)
				cout << "Невозможно прочитать файл" << endl;
			break;
		case 3:
			cout << "Введите имя файла" << endl;
			cin >> file_name;
			cin >> t1;
			k = del_file(file_name, t1);
			if (k < 0)
				cout << "Невозможно прочитать файл" << endl;
			break;
		case 4:
			cout << "Введите имя файла" << endl;
			cin >> file_name;
			cout << "Введите значения записи" << endl;
			cin >> t1;
			k = change_file(file_name, t1);
			if (k < 0)
				cout << "Невозможно прочитать файл" << endl;
			if (k == 0)
				cout << "Изменения не записаны" << endl;
			break;
		case 5:
			cout << "Введите имя файла" << endl;
			cin >> file_name;
			k = add_file(file_name);
			if (k < 0)
				cout << "Невозможно прочитать файл" << endl;
			break;
		}
	} while (c != 0);
}

