#include <iostream>
#include <cstdlib>
#include <time.h>
#include <deque>
using namespace std;

typedef deque<int> deq;//���������� ��� ��� ������ � ��������

//������� ��� ������������ �������
deq make_deque(int n)
{
	deq d;//������ �������
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		//���������� ��������� ������������ �����
		float a = rand() / 100.0 - 50.0;
		d.push_back(a);//��������� � � ����� �������
	}
	return d;//���������� ������� ��� ������� ������ �������
}

//������� ��� ������ �������
void print_deque(deq d)
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
}

//����� ������������� ��������
int find_max(deq d)
{
	//����� ���������� ������ ������� ��� ������������
	int max = d[0];
	//��� � ����� �� 2-�� �������� � ����
	for (int i = 1; i < d.size(); i++)
		if (d[i] > max)
			max = d[i];
	//���������� ���������
	return max;
}

//����� �������� ���������������
int srednee(deq d)
{
	int s = 0;
	for (int i = 0; i < d.size(); i++)
		s += d[i];
	return s / d.size();
}

//�������� �������� �� ��������� el
void del_from_deque(deq &d, int el)
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
void add(deq &d, int el)
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

	int max_el = find_max(d); //���� ��������
	cout << "Max: " << max_el << endl;
	d.push_back(max_el); //��������� � ����� ����������
	cout << "Result: ";
	print_deque(d);

	cout << "Delete key: ";
	int key;
	cin >> key;
	del_from_deque(d, key); //���������� ��������
		
	int sred = srednee(d);
	cout << "Srednee: " << sred << endl;
	add(d, sred);
	print_deque(d);
	system("pause");
}