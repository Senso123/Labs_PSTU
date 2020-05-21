#pragma once
#include <iostream>
#include <map> //�������
using namespace std;

//������������������� �����
template<class T>
class Container
{
	map<int, T> v; //��������� �������
	int len; //����� �������
public:
	Container(void); //����������� ��� ����������
	Container(int n); //����������� � �����������
	void Print(); //������
	T find_max();
	T find_mean();
	void insert_map(T item, int pos);
	void delete_from_map(T item);
	void add_map(T mean);
	int size() { return len; }
	~Container(void); //����������
};

//���������� �������
//����������� ��� ����������
template <class T>
Container<T>::Container()
{
	len = 0;
}

//����������
template <class T>
Container<T>::~Container(void)
{
}

//����������� c �����������
template <class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.insert(make_pair(i, a));
	}
	len = n;
}

//����� ����������
template <class T>
void Container<T>::Print()
{
	map<int, T>::iterator it;
	cout << endl;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << "<" << it->first << ": " << it->second << ">  ";
	}
	cout << endl;
}

template < class T >
T Container<T>::find_max()
{
	map<int, T>::iterator it = v.begin();
	T t = it->second;
	for (it = v.begin(); it != v.end(); it++)
	{
		if (it->second > t)
			t = it->second;
	}
	return t;
}

template < class T >
void Container<T>::insert_map(T item, int pos)
{
	v.insert(make_pair(pos, item));
}

template<class T>
void Container<T>::delete_from_map(T item)
{
	map<int, T>::iterator current, j;
	j = v.begin();
	int k = v.size();
	for (int i = 0; i < k; i++)
	{
		current = j;
		j++;
		if ((current->second) == item)
			v.erase(current);
	}
}

template<class T>
T Container<T>::find_mean()
{
	T sum(0, 0);
	map<int, T>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		sum = sum + it->second;
	return(sum / v.size());
}

template<class T>
void Container<T>::add_map(T mean)
{
	map<int, T>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		it->second = it->second + mean;
}