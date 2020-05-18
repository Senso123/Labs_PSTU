#include <iostream>
#include <map>
#include <time.h>
#include "Time.h"
using namespace std;

typedef map<int, Time> TMap;//���������� ��� ��� ������ �� ��������
typedef TMap::iterator it;//��������

//������� ��� ������������ �������
TMap make_map(int n)
{
	srand(time(NULL));
	TMap m;//������ �������
	Time t;
	for (int i = 0; i < n; i++)
	{
		//���������� ��������� �����
		int a = 0 + rand() % 59;
		int b = 0 + rand() % 59;
		Time t(a, b);
		//������� ���� � ��������� �� � �������
		m.insert(make_pair(i, t));
	}
	return m;//���������� ������� ��� ��������� ������ �������
}
//������� ��� ������ �������
void print_map(TMap m)
{
	//�������� ���������� ������� � ������� ���������
	for (it it2 = m.begin(); it2 != m.end(); it2++)
	{
		cout << "<" << it2->first << ": " << it2->second << ">  ";
	}
	cout << endl;
}

//����� ������������� ��������
Time find_max(TMap m)
{
	it it2 = m.begin();
	Time t = it2->second;
	for (it2 = m.begin(); it2 != m.end(); it2++)
	{
		if (it2->second > t)
			t = it2->second;
	}
	return t;
}

//���������� �������� ��������
Time find_mean(TMap m)
{
	Time sum(0, 0);
	for (it it2 = m.begin(); it2 != m.end(); it2++)
	{
		sum = sum + it2->second;
	}
	return(sum / m.size());
}

//������� �� �������� �������
void add_map(TMap &m, Time item, int pos)
{
	m.insert(make_pair(pos, item));
}

//�������� ���������
void delete_from_map(TMap &m, Time item)
{
	it current, j; //������ ��� ���������
	j = m.begin(); //������ �������
	int k = m.size(); //������ �������
	for (int i = 0; i < k; i++) //� ����� �������� � �����������
	{
		current = j; //��������� � current ��������� �� ������� �������
		j++; //������������ j �� ��������� �������
		if ((current->second) == item) //���� ����� ���, ������� ���� �������, �� �������.
			m.erase(current);			//���� �������� ����, ��� �� ������ ���������. 
		//����� ������� �� ������� � �������� ��������
	}
}

//����������� �� ���� ���������
void add(TMap &m, Time item)
{
	for (it it2 = m.begin(); it2 != m.end(); it2++)
		it2->second = it2->second + item;
}

void main()
{
	int n;
	cout << "N: "; 
	cin >> n;//���������� ���������
	TMap m = make_map(n);//������� �������
	print_map(m);//���������� �������
	cout << endl;

	//���������� ������������� �������� � ����� ����������
	Time maxItem = find_max(m);
	cout << "Max: " << maxItem << endl;
	//��������� �� �������, ������ ������� �������, ����� ��� �������������� ���������� ������� ������� �������� � �����
	add_map(m, maxItem, m.size());
	cout << "Result: ";
	print_map(m);
	cout << endl;

	//�������� ��������� � �������� ���������
	Time key;
	cout << "Time for delete:" << endl;
	cin >> key;
	delete_from_map(m, key);
	cout << "Result: ";
	print_map(m);
	cout << endl;

	//���������� � ������� �������� �������� ���������������
	Time srednee = find_mean(m);
	cout << "Srednee: " << srednee << endl;
	add(m, srednee);
	cout << "Result: ";
	print_map(m);
	cout << endl;
	system("pause");
}