#include "Time.h"
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
typedef deque<Time> TDeq;
Time s;

//формирование очереди
TDeq make_deque(int n)
{
	Time a;
	TDeq v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

//печать очереди
void print_deque(TDeq v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

//для поиска одинаковых
struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};

struct Comp_less // для сортировки по убыванию
{
public:
	bool operator()(Time t1, Time t2)
	{
		if (t1 > t2)return true;
		else return false;
	}
};

void add_mean(Time& t)  //к каждому элементу прибавляем значение s
{
	t = t + s;
}

void mySum(Time t)  //вычисление суммы всех элементов
{
	s = s + t;
}

void main()
{
	int n;
	cout << "N: ";
	cin >> n;
	TDeq d;
	d = make_deque(n);
	print_deque(d);
	cout << endl;

	Time m;
	TDeq::iterator i;
	i = max_element(d.begin(), d.end());
	m = *(i);
	cout << "Max: " << m << endl;
	d.insert(d.begin() + d.size(), m);
	cout << "Result: " << endl;
	print_deque(d);
	cout << endl;

	cout << "Value for delete: " << endl;
	cin >> s;
	i = remove_if(d.begin(), d.end(), Equal_s()); //получаем итератор на начало "мусора", того, что надо удалить
	d.erase(i, d.end()); //удаляем этот мусор с начала этого итератора и до конца Очереди
	cout << "Result: " << endl;
	print_deque(d);
	cout << endl;

	cout << "Find: " << endl;
	cin >> s;
	i = find_if(d.begin(), d.end(), Equal_s());
	if (i != d.end())//если нет конца очереди
		cout << *(i) << endl;
	else
		cout << "Not found!" << endl;

	cout << "Sort ybivanie: " << endl;
	sort(d.begin(), d.end(), Comp_less());
	print_deque(d);
	cout << "Sort vozrastanie: " << endl;
	sort(d.begin(), d.end());
	print_deque(d);
	cout << endl;

	s = Time(0, 0);
	for_each(d.begin(), d.end(), mySum);
	s = s / d.size();
	cout << "Srednee: " << s << endl;
	for_each(d.begin(), d.end(), add_mean);
	cout << "Result: " << endl;
	print_deque(d);
	cout << endl;

	system("pause");
}