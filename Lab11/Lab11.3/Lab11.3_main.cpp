#include "Time.h"
#include "Vector.h"
#include <cstdlib>
#include <time.h>
using namespace std;

void main()
{
	Vector<Time> vec(5);//������� ������ �� 5 ���������
	vec.Print();//������ �������
	cout << endl;

	Time max_el = vec.find_max(); //���� ��������
	cout << "Max: " << max_el << endl;
	vec.Insert_end(max_el); //���������� ������� � �����
	cout << "Result: ";
	vec.Print();//������ �������
	cout << endl;

	cout << "Key to delete: ";
	Time key;
	cin >> key;
	vec.Del(key);
	cout << "Result: ";
	vec.Print();//������ �������
	cout << endl;

	Time sred = vec.Srednee();
	cout << "Srednee: " << sred << endl;
	vec.Add(sred);
	cout << "Result: ";
	vec.Print();//������ �������
	cout << endl;
	system("pause");
}