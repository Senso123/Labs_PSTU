#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Time
{
public:
	Time();
	Time(int m, int s);
	Time(const Time& t);

	//over
	Time& operator=(const Time&);
	Time operator +(const Time&);
	bool operator<=(const Time&);
	bool operator==(const Time&);
	bool operator!=(const Time&);

	//ввод вывод
	friend ostream& operator<<(ostream& out, const Time& t);
	friend istream& operator>>(istream& in, Time& t);

	friend fstream& operator<<(fstream& fout, const Time& t);
	friend fstream& operator>>(fstream& fin, Time& t);
public:
	~Time();
private:
	int min, sec;
};