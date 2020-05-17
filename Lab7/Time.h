#include <iostream>
#include<string>
using namespace std;
class Time
{
	int min, sec;
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	Time& operator=(const Time&);
	Time operator+(Time&);
	Time operator+(const Time& t);
	Time operator+(Time k);
	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const Time&);
	friend istream& operator>>(istream& in, Time&);
public:
	virtual ~Time(void) {};
};
/////////////////////////////////////////////////////////////////////////////////////////////

