#include <deque>
#include <cstdlib>
#include <time.h>
#include "Time.h"
using namespace std;

typedef deque<Time> deq;//���������� ��� ��� ������ � ��������

//������� ��� ������������ �������
deq make_deque(int n)
{
	deq d;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		//���������� ��������� �����
		int a = 0 + rand() % 59;
		int b = 0 + rand() % 59;
		Time t(a, b);
		d.push_back(t);
	}
	return d;
}

//������� ��� ������ �������
void print_deque(deq d)
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
}

//����� ������������� ��������
Time find_max(deq d)
{
	//����� ���������� ������ ������� ��� ������������
	Time max = d[0];
	//��� � ����� �� 2-�� �������� � ����
	for (int i = 1; i < d.size(); i++)
		if (d[i] > max)
			max = d[i];
	//���������� ���������
	return max;
}

//����� �������� ���������������
Time srednee(deq d)
{
	Time s = Time(0, 0);
	for (int i = 0; i < d.size(); i++)
		s = s + d[i];
	return s / d.size();
}

//�������� �������� �� ��������� el
void del_from_deque(deq &d, Time el)
{
	int i = 0;
	//��� � ����� �� ������� � ���� ����� �������� �� ��������� el
	for (i = 0; i < d.size(); i++)
		if (d[i] == el) //���� �����, ������� �� �����
			break;
	//���� i ����� ������� �������, ������ ����� �� ����� ����� � ������� �� �����
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

//����������� �� ���� ��������� �������
void add(deq &d, Time el)
{
	for (int i = 0; i < d.size(); i++)
		d[i] = d[i] + el;
}

//�������� �������
void main()
{
	deq d;//�������
	int n;
	cout << "N: ";
	cin >> n;
	d = make_deque(n);//������������ �������
	print_deque(d);//������ �������
	cout << endl;

	Time max_el = find_max(d); //���� ��������
	cout << "Max: " << max_el << endl;
	d.push_back(max_el); //��������� � ����� ����������
	cout << "Result: ";
	print_deque(d);

	cout << "Delete key: ";
	Time key;
	cin >> key;
	del_from_deque(d, key); //���������� ��������

	Time sred = srednee(d);
	cout << "Srednee: " << sred << endl;
	add(d, sred);
	print_deque(d);
	system("pause");
}