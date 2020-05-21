#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)
		return -1;
	int n;
	Time t;
	cout << "Введите количество записей" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stream << t << endl;
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time t;
	int i = 0;
	while (stream >> t)
	{
		cout << t << endl;
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Time t1)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	int i = 0;
	Time t;
	while (stream >> t)
	{
		i++;
		if (t == t1)
			temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int change_file(const char* f_name, Time t1)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time t;
	Time temp1;
	int i = 0, l = 0;
	while (stream >> t)
	{
		i++;
		if (t == t1)
		{
			temp1 = t + Time(1, 30);
			if (temp1 <= Time(0, 0))
				temp << t;
			else
				temp << temp1;
			l++;
		}
		else temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_file(const char* f_name)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time t, t1;
	int n, i = 0, l = 0;
	cout << "Введите количество записей" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите значения" << endl;
		cin >> t1;
		temp << t1 << endl;
	}
	while (stream >> t)
	{
		temp << t;
		i++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}