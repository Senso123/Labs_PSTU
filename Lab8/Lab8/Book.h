#pragma once
#include "Print.h"
class Book :
	public Print
{
public:
	Book(void);
public:
	~Book(void);
	void Show();
	void Input();
	Book(string, string, int, string);
	Book(const Book &);
	int Get_countPage(){ return countPage; }
	void Set_countPage(int);
	string Get_publishingHouse() { return publishingHouse; }
	void Set_publishingHouse(string);
	Book& operator=(const Book&);
protected:
	int countPage;
	string publishingHouse;
};

