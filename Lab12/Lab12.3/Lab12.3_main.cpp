#include "Container.h"
#include <iostream>
#include "Time.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int n; //���������� ��������� � ����������
	cout << "N: "; 
	cin >> n;
	Container <Time> v(n);//������� ��������
	v.Print();//���������� ���������

	//���������� ������������� �������� � ����� ���������
	Time maxItem = v.find_max();
	cout << "Max: " << maxItem << endl;
	v.insert_map(maxItem, v.size());
	cout << "Result: ";
	v.Print();
	cout << endl;

	//�������� ��������� � �������� ���������
	Time val;
	cout << "Value for delete: " << endl;
	cin >> val;
	v.delete_from_map(val);
	cout << "Result: ";
	v.Print();
	cout << endl;

	//���������� � ������� �������� �������� ���������������
	Time meanItem = v.find_mean();
	cout << "Srednee: " << meanItem << endl;
	v.add_map(meanItem);
	cout << "Result: ";
	v.Print();
	cout << endl;
	system("pause");
}