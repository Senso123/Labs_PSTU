#pragma once
#include <iostream>
#include <ctime>
using namespace std;

struct point
{
	int data;	//информационное поле
	point* next;	//адресное поле
};

//создание однонаправленного списка
//добавление в конец
point* make_list(int n)
{
	srand(time(0)); // автоматическая рандомизация
	point*beg;	//указатель на первый элемент
	point*p, *r;	//вспомогательные указатели
	beg = new(point);	//выделяем память под первый элемент
	beg->data = rand() % 100 + 1;	//заполняем значение информационного поля
	beg->next = 0;	//обнуляем адресное поле
	p = beg;	//ставим на этот элемент указатель p (последний элемент)
	for (int i = 0; i < n - 1; i++)
	{
		r = new(point);	//создаем новый элемент
		r->data = rand() % 100 + 1;
		r->next = 0;
		p->next = r;	//связываем p и r
		p = r;	//ставим на r указатель p (последний элемент)
	}
	return beg;	//возвращаем beg как результат функции
}

//печать списка
void print_list(point* beg)
{
	if(beg == 0)
		cout << "Список пуст!" << endl;
	point* p = beg;//начало списка
	while (p != 0)
	{
		cout << p->data << " ";
		p = p->next;//переход к следующему элементу
	}
	cout << endl;
}

//удаление элемента с номером k из списка
point* del_point(point*beg, int k)
{
	point*p = beg;
	if (k == 0)//удаление первого элемента
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//проходим по списку до элемента с номером k-1
	for (int i = 1; i < k && p->next != 0; i++)
		p = p->next;
	/*если такого элемента в списке нет, то возвращаем указатель на начало списка в качестве результата функции*/
	if (p->next == 0) 
		return beg;
	point* r = p->next;//ставим указатель r на k-й элемент
	p->next = r->next;//связываем k-1 и k+1 элемент
	delete r;//удаляем k-й элемент из памяти
	return beg;
}

//задание для работы со списком
point* task_for_list(point *beg)
{
	point *p = beg;
	//ищем номер элемента для удаления
	int pos = -1;
	int k = 0; //счётчик позиций элементов
	while (p != 0)
	{
		if (p->data % 2 == 0)
			pos = k;
		p = p->next;//переход к следующему элементу
		k++;
	}
	point* rez = beg;
	if (k == -1)
		cout << "Нужный элемент для удаления не найден!" << endl;
	else
		rez = del_point(beg, pos);
	return rez;
}

//очистка списка
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

