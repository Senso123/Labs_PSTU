#pragma once
#include <vector>
#include <iostream>
using namespace std;

//������ ������
template<class T>
class Vector
{
	vector <T> v;//���������������� ��������� ��� �������� ��������� �������
	int len;
public:
	Vector(void);//����������� ��� ���������
	Vector(int n);//����������� � ����������
	void Print();//������
	~Vector(void);//����������

	T Srednee();//���������� �������� ���������������
	T find_max();
	void Insert_end(T el);//���������� �������� el � ����� �������
	void Del(T el); //������� ������� el
	void Add(T el); //��������� �� ���� ��������� ������� el
};

//����������� ��� ���������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}

//����������
template <class T>
Vector<T>::~Vector(void)
{
}

//����������� � ����������
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

//������
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

//��������� ������� ��������������
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

//��������� �� ���� ��������� ������� el
template<class T>
void Vector<T>::Add(T el)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + el;
}

//�������� �������� el
template<class T>
void Vector<T>::Del(T el)
{
	int i = 0;
	//��� � ����� �� ������� � ���� ����� �������� �� ��������� el
	for (i = 0; i < v.size(); i++)
		if (v[i] == el) //���� �����, ������� �� �����
			break;
	//���� i ����� ������� �������, ������ ����� �� ����� ����� � ������� �� �����
	if (i == v.size())
		cout << "Element not found!" << endl;
	else
	{
		v.erase(v.begin() + i);
		len--;
	}
}

//���������� �������� el � ����� �������
template <class T>
void Vector<T>::Insert_end(T el)
{
	v.push_back(el);
	len++;
}