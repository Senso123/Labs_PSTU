#include "Time.h"
#include <time.h>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

typedef multimap<Time, int> myMap;
myMap::iterator it;
Time s;

myMap createMap(int size)
{
	srand(time(NULL));
	myMap st;
	for (int i = 0; i < size; i++)
	{
		//генерируем рандомные числа
		int a = 0 + rand() % 59;
		int b = 0 + rand() % 59;
		Time t(a, b);
		st.insert(make_pair(t, i));
	}
	return st;
}

void printMap(myMap st)
{
	for (it = st.begin(); it != st.end(); it++)
		cout << "<" << it->first << ",  " << it->second << "> ";
	cout << endl;
}

void printReverse(myMap st)
{
	myMap::reverse_iterator rit;
	for (rit = st.rbegin(); rit != st.rend(); rit++)
	{
		cout << "<" << rit->first << ",  " << rit->second << "> ";
	}
	cout << endl;
}

myMap add_mean(Time t, myMap st)
{
	Time tt;
	myMap st1;
	for (it = st.begin(); it != st.end(); it++)
	{
		tt = it->first;
		tt = tt + t;
		st1.insert(make_pair(tt, it->second));
	}
	return st1;
}

void deleteEqualS(myMap& st)
{
	Time t;
	myMap::iterator itDel;
	for (it = st.begin(); it != st.end(); it++)
	{
		t = it->first;
		if (s == t)
		{
			itDel = it;
			it--;
			st.erase(itDel);
		}
	}
}

void main()
{
	int n;
	cout << "N: ";
	cin >> n;
	myMap mapTime = createMap(n);
	printMap(mapTime);
	cout << endl;

	it = max_element(mapTime.begin(), mapTime.end());
	Time max_el = it->first;
	cout << "Max: " << max_el << endl;
	mapTime.insert(make_pair(max_el, mapTime.size()));
	printMap(mapTime);
	cout << endl;

	cout << "Sort ybivanie: " << endl;
	//просто выводим множество в обратном порядке, потому что его НИКАК не отсортировать, оно само по себе сортируется по возрастанию ключей
	printReverse(mapTime); 
	cout << endl;

	cout << "Time for delete: " << endl;
	cin >> s;
	deleteEqualS(mapTime);
	cout << "Result: " << endl;
	printMap(mapTime);
	cout << endl;

	s = Time(0, 0);
	for (it = mapTime.begin(); it != mapTime.end(); it++)
		s = s + it->first;
	s = s / mapTime.size();
	cout << "Srednee: " << s << endl;
	mapTime = add_mean(s, mapTime);
	cout << "Result: " << endl;
	printMap(mapTime);

	system("pause");
}