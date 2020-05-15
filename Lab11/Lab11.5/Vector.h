#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T>
class Vector
{
	queue <T> s;//���������
	int len;//������ ����������
public:
	Vector();//����������� ��� ����������
	Vector(int n);//����������� � �����������
	Vector(const Vector<T>&);//����������� �����������
	void Print();
	T find_srednee();
	T find_max();
	void insert_end(T el);
	void add(T m);
	void del(T m);
};

//����������� ������� � ������
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

//����������� ������� � �������
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

//����������� ��� ����������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}

//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//�������� � ������� ������� �
	}
	len = s.size();
}

//����������� �����������
template <class T>
Vector<T>::Vector(const Vector<T> &Vec)
{
	len = v.len;
	//�������� �������� ������� Vec.s � ������ v
	vector v = copy_queue_to_vector(Vec.s);
	//�������� ������ v � ������� s
	s = copy_vector_to_queue(v);
}

//������
template <class T>
void Vector<T>::Print()
{
	//�������� ������� � ������
	vector<T> v = copy_queue_to_vector(s);
	while (!s.empty())//���� ������� �� ������
	{
		cout << s.front() << " ";//����� �������� � ������ �������
		s.pop();//������� ������� �� �������
	}
	cout << endl;
	//�������� ������ � �������
	s = copy_vector_to_queue(v);
}

//������� ��������������
template <class T>
T Vector<T>::find_srednee()
{
	//�������� ������� � ������
	vector<T> v = copy_queue_to_vector(s);
	int n = 1;//���������� ��������� � �������
	T sum = s.front();//��������� �������� ��� �����
	s.pop();//������� ������� �� ������� �������
	while (!s.empty())//���� ������� �� ������
	{
		sum = sum + s.front();//��������� � ����� ������� �� ������� �������
		s.pop();//������� ������� �� ������� �������
		n++;//����������� ���������� ���������
	}
	//�������� ������ � �������
	s = copy_vector_to_queue(v);
	return sum / n;
}

//������������ �������
template <class T>
T Vector<T>::find_max()
{
	//�������� ������� � ������
	vector<T> v = copy_queue_to_vector(s);
	T max = s.front();//��������� �������� ��� ������
	s.pop();//������� ������� �� ������� �������
	while (!s.empty())//���� ������� �� ������
	{
		//���������� �������
		if (s.front() > max)
			max = s.front();
		s.pop();//������� ������� �� ������� �������
	}
	//�������� ������ � �������
	s = copy_vector_to_queue(v);
	return max;
}

//���������� �� ���� ��������� �������� m
template <class T>
void Vector<T>::add(T m)
{
	vector<T> v = copy_queue_to_vector(s);
	for (int i = 0; i < s.size(); i++)
		v[i] = v[i] + m;
	s = copy_vector_to_queue(v);
}

//�������� �������� m
template <class T>
void Vector<T>::del(T m)
{
	vector<T> v;
	T t;
	while (!s.empty())//���� ������� �� ������
	{
		t = s.front();//�������� ������� �� ������� �������
		if (!(t == m))
			v.push_back(t);
		else
			len--;
		s.pop();//������� ������� �� �������
	}
	s = copy_vector_to_queue(v);//�������� ������ � �������
}

template <class T>
void Vector<T>::insert_end(T el)
{
	s.push(el);
}