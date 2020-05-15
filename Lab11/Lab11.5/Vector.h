#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T>
class Vector
{
	queue <T> s;//контейнер
	int len;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	Vector(const Vector<T>&);//конструктор копирования
	void Print();
	T find_srednee();
	T find_max();
	void insert_end(T el);
	void add(T m);
	void del(T m);
};

//копирование очереди в вектор
template <class T>
vector<T> copy_queue_to_vector(queue<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.front());
		s.pop();
	}
	return v;
}

//копирование вектора в очередь
template <class T>
queue<T> copy_vector_to_queue(vector<T> v)
{
	queue<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	len = 0;
}

//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в очередь элемент а
	}
	len = s.size();
}

//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T> &Vec)
{
	len = v.len;
	//копируем значения очереди Vec.s в вектор v
	vector v = copy_queue_to_vector(Vec.s);
	//копируем вектор v в очередь s
	s = copy_vector_to_queue(v);
}

//печать
template <class T>
void Vector<T>::Print()
{
	//копируем очередь в вектор
	vector<T> v = copy_queue_to_vector(s);
	while (!s.empty())//пока очередь не пустая
	{
		cout << s.front() << " ";//вывод элемента в начале очереди
		s.pop();//удаляем элемент из вершины
	}
	cout << endl;
	//копируем вектор в очередь
	s = copy_vector_to_queue(v);
}

//среднее арифметическое
template <class T>
T Vector<T>::find_srednee()
{
	//копируем очередь в вектор
	vector<T> v = copy_queue_to_vector(s);
	int n = 1;//количество элементов в очереди
	T sum = s.front();//начальное значение для суммы
	s.pop();//удаляем элемент из вершины очереди
	while (!s.empty())//пока очередь не пустая
	{
		sum = sum + s.front();//добавляем в сумму элемент из вершины очереди
		s.pop();//удаляем элемент из вершины очереди
		n++;//увеличиваем количество элементов
	}
	//копируем вектор в очередь
	s = copy_vector_to_queue(v);
	return sum / n;
}

//максимальный элемент
template <class T>
T Vector<T>::find_max()
{
	//копируем очередь в вектор
	vector<T> v = copy_queue_to_vector(s);
	T max = s.front();//начальное значение для поиска
	s.pop();//удаляем элемент из вершины очереди
	while (!s.empty())//пока очередь не пустая
	{
		//сравниваем элемент
		if (s.front() > max)
			max = s.front();
		s.pop();//удаляем элемент из вершины очереди
	}
	//копируем вектор в очередь
	s = copy_vector_to_queue(v);
	return max;
}

//добавление ко всем элементам элемента m
template <class T>
void Vector<T>::add(T m)
{
	vector<T> v = copy_queue_to_vector(s);
	for (int i = 0; i < s.size(); i++)
		v[i] = v[i] + m;
	s = copy_vector_to_queue(v);
}

//удаление элемента m
template <class T>
void Vector<T>::del(T m)
{
	vector<T> v;
	T t;
	while (!s.empty())//пока очередь не пустая
	{
		t = s.front();//получаем элемент из вершины очереди
		if (!(t == m))
			v.push_back(t);
		else
			len--;
		s.pop();//удаляем элемент из очереди
	}
	s = copy_vector_to_queue(v);//копируем вектор в очередь
}

template <class T>
void Vector<T>::insert_end(T el)
{
	s.push(el);
}