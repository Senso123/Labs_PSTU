#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
#include "Time.h"
using namespace std;

void main()
{
	Vector<Time> vec(5);//������� ������ �� 5 ���������
	vec.Print();//������ �������
	cout << endl;

	Time max_el = vec.find_max(); //���� ��������
	cout << "Max: " << max_el << endl;
	vec.insert_end(max_el); //���������� ������� � �����
	cout << "Result: ";
	vec.Print();//������ �������
	cout << endl;

	cout << "Key to delete: ";
	Time key;
	cin >> key;
	vec.del(key);
	cout << "Result: ";
	vec.Print();//������ �������
	cout << endl;

	Time sred = vec.find_srednee();
	cout << "Srednee: " << sred << endl;
	vec.add(sred);
	cout << "Result: ";
	vec.Print();//������ �������
	cout << endl;
	system("pause");
}