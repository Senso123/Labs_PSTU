#pragma once
#include <vector>
#include <iostream>
using namespace std;

//шаблон класса
template<class T>
class Vector
{
	vector <T> v;//последовательный контейнер для хранения элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметра
	Vector(int n);//конструктор с параметром
	void Print();//печать
	~Vector(void);//деструктор

	T Srednee();//вычисление среднего арифметического
	T find_max();
	void Insert_end(T el);//добавление элемента el В конец вектора
	void Del(T el); //удалить элемент el
	void Add(T el); //прибавить ко всем элементам вектора el
};

//конструктор без параметра
template <class T>
Vector<T>::Vector()
{
	len = 0;
}

//деструктор
template <class T>
Vector<T>::~Vector(void)
{
}

//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

//печать
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

//вычислить среднее арифметическое
template<class T>
T Vector<T>::Srednee()
{
	T s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}

template<class T>
T Vector<T>::find_max()
{
	T max = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] > max)
			max = v[i];
	return max;
}

//прибавить ко всем элементам вектора el
template<class T>
void Vector<T>::Add(T el)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + el;
}

//удаление элемента el
template<class T>
void Vector<T>::Del(T el)
{
	int i = 0;
	//идём в цикле по очереди и ищем номер элемента со значением el
	for (i = 0; i < v.size(); i++)
		if (v[i] == el) //если нашли, выходим из цикла
			break;
	//если i равен размеру очереди, значит дошли до конца цикла и элемент не нашли
	if (i == v.size())
		cout << "Element not found!" << endl;
	else
	{
		v.erase(v.begin() + i);
		len--;
	}
}

//добавление элемента el В конец вектора
template <class T>
void Vector<T>::Insert_end(T el)
{
	v.push_back(el);
	len++;
}