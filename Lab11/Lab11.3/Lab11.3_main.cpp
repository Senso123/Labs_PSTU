#include "Time.h"
#include "Vector.h"
#include <cstdlib>
#include <time.h>
using namespace std;

void main()
{
	Vector<Time> vec(5);//создать вектор из 5 элементов
	vec.Print();//печать вектора
	cout << endl;

	Time max_el = vec.find_max(); //ищем максимум
	cout << "Max: " << max_el << endl;
	vec.Insert_end(max_el); //производим вставку в конец
	cout << "Result: ";
	vec.Print();//печать вектора
	cout << endl;

	cout << "Key to delete: ";
	Time key;
	cin >> key;
	vec.Del(key);
	cout << "Result: ";
	vec.Print();//печать вектора
	cout << endl;

	Time sred = vec.Srednee();
	cout << "Srednee: " << sred << endl;
	vec.Add(sred);
	cout << "Result: ";
	vec.Print();//печать вектора
	cout << endl;
	system("pause");
}