#include "Time.h"

Time::Time() //конструктор без параметров
{
	min = 0;
	sec = 0;
}

Time::Time(int M, int S) //конструктор с параметрами
{
	min = M;
	sec = S;
}

Time::Time(const Time& t) //конструторк копирования
{
	min = t.min;
	sec = t.sec;
}

Time::~Time() //деструктор
{
}

Time& Time::operator=(const Time& t)

{
	if (&t == this)
		return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 ) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

bool Time::operator<=(const Time& t)
{
	return this->min <= t.min && sec <= t.sec;
}

bool Time::operator!=(const Time& t)
{
	return this->min != t.min && sec != t.sec;
}

bool Time::operator==(const Time& t)
{
	return this->min == t.min && sec == t.sec;
}

//ввод-ввывод
ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << " : " << t.sec;
	return out;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "min :";
	in >> t.min;
	cout << "sec :";
	in >> t.sec;
	return in;
}

fstream& operator<<(fstream& fout, const Time& t)
{
	fout << t.min << endl;
	fout << t.sec << endl;
	return fout;
}

fstream& operator>>(fstream& fin, Time& t)
{
	fin >> t.min;
	fin >> t.sec;
	return fin;
}