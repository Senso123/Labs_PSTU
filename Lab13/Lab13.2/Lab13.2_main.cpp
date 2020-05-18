#include "Time.h"
#include <time.h>
#include <iostream>
#include <queue>
using namespace std;

typedef queue<Time> que;
typedef vector<Time> vec;
Time s;

que make_queue(int n)
{
	srand(time(NULL));
	que q;
	for (int i = 0; i < n; i++)
	{
		//генерируем рандомные числа
		int a = 0 + rand() % 59;
		int b = 0 + rand() % 59;
		Time t(a, b);
		q.push(t); //добавление в очередь
	}
	return q;//вернуть очередь как результат функции
}

void print_queue(que q)
{
	while (!q.empty())//пока очередь не пустая
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

//копирует очередь в вектор
vec copy_queue_to_vector(que q)
{
	vec v;
	while (!q.empty())//пока очередь не пустая
	{
		//добавить в вектор элемент из вершиы очереди
		v.push_back(q.front());
		q.pop();
	}
	return v; //вернуть вектор как результат функции
}

//копирует вектор в очередь
que copy_vector_to_queue(vec v)
{
	que q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);//добавить в очередь элемент вектора
	}
	return q; //вернуть очередь как результат функции
}

void mySum(Time t)  //вычисление суммы всех элементов
{
	s = s + t;
}

//для поиска одинаковых
struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};

void add_mean(Time& t)  //к каждому элементу прибавляем значение s
{
	t = t + s;
}

struct Comp_less // для сортировки по убыванию
{
public:
	bool operator()(Time t1, Time t2)
	{
		if (t1 > t2)return true;
		else return false;
	}
};

void main()
{
	que q;
	int n;
	cout << "N: ";
	cin >> n;
	q = make_queue(n);
	cout << endl;
	print_queue(q);
	cout << endl;

	vec v = copy_queue_to_vector(q);
	vec::iterator i;
	i = max_element(v.begin(), v.end());
	Time max_el = *(i);
	cout << "Max: " << max_el << endl;
	q.push(max_el);
	print_queue(q);
	cout << endl;

	cout << "Value for delete: " << endl;
	cin >> s;
	v = copy_queue_to_vector(q);
	i = remove_if(v.begin(), v.end(), Equal_s()); //получаем итератор на начало "мусора", того, что надо удалить
	v.erase(i, v.end()); //удаляем этот мусор с начала этого итератора и до конца вектор
	q = copy_vector_to_queue(v);
	cout << "Result: " << endl;
	print_queue(q);
	cout << endl;

	//к этому моменту содержимое вектора совпадает с содержимым очереди
	cout << "Find: " << endl;
	cin >> s;
	i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end())//если нет конца вектора
		cout << *(i) << endl;
	else
		cout << "Not found!" << endl;
	cout << endl;

	cout << "Sort ybivanie: " << endl;
	sort(v.begin(), v.end(), Comp_less());
	q = copy_vector_to_queue(v);
	print_queue(q);
	cout << "Sort vozrastanie: " << endl;
	sort(v.begin(), v.end());
	q = copy_vector_to_queue(v);
	print_queue(q);
	cout << endl;

	//не нужно лишний раз копировать очередь в вектор, на этот момент их содержимое совпадает
	s = Time(0, 0);
	for_each(v.begin(), v.end(), mySum);
	s = s / v.size();
	cout << "Srednee: " << s << endl;
	for_each(v.begin(), v.end(), add_mean);
	q = copy_vector_to_queue(v);
	cout << "Result: " << endl;
	print_queue(q);
	cout << endl;
	system("pause");
}