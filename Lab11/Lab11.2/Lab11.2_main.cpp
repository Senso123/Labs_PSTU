#include <deque>
#include <cstdlib>
#include <time.h>
#include "Time.h"
using namespace std;

typedef deque<Time> deq;//определяем тип для работы с очередью

//функция для формирования очереди
deq make_deque(int n)
{
	deq d;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		//генерируем рандомные числа
		int a = 0 + rand() % 59;
		int b = 0 + rand() % 59;
		Time t(a, b);
		d.push_back(t);
	}
	return d;
}

//функция для печати очереди
void print_deque(deq d)
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
}

//поиск максимального элемента
Time find_max(deq d)
{
	//задаём изначально первый элемент как максимальный
	Time max = d[0];
	//идём в цикле со 2-го элемента и ищем
	for (int i = 1; i < d.size(); i++)
		if (d[i] > max)
			max = d[i];
	//возвращаем результат
	return max;
}

//поиск среднего арифметического
Time srednee(deq d)
{
	Time s = Time(0, 0);
	for (int i = 0; i < d.size(); i++)
		s = s + d[i];
	return s / d.size();
}

//удаление элемента со значением el
void del_from_deque(deq &d, Time el)
{
	int i = 0;
	//идём в цикле по очереди и ищем номер элемента со значением el
	for (i = 0; i < d.size(); i++)
		if (d[i] == el) //если нашли, выходим из цикла
			break;
	//если i равен размеру очереди, значит дошли до конца цикла и элемент не нашли
	if (i == d.size())
		cout << "Element not found!" << endl;
	else
	{
		d.erase(d.begin() + i);
		cout << "Result: ";
		print_deque(d);
		cout << endl;
	}
}

//прибавления ко всем элементам среднее
void add(deq &d, Time el)
{
	for (int i = 0; i < d.size(); i++)
		d[i] = d[i] + el;
}

//основная функция
void main()
{
	deq d;//очередь
	int n;
	cout << "N: ";
	cin >> n;
	d = make_deque(n);//формирование очереди
	print_deque(d);//печать очереди
	cout << endl;

	Time max_el = find_max(d); //ищем максимум
	cout << "Max: " << max_el << endl;
	d.push_back(max_el); //добавляем в конец контейнера
	cout << "Result: ";
	print_deque(d);

	cout << "Delete key: ";
	Time key;
	cin >> key;
	del_from_deque(d, key); //производим удаление

	Time sred = srednee(d);
	cout << "Srednee: " << sred << endl;
	add(d, sred);
	print_deque(d);
	system("pause");
}