#pragma once
#include <string>
#include <iostream>
#include "Dialog.h"
using namespace std;

//конструктор
Dialog::Dialog()
{
	EndState = 0;
}

//деструктор
Dialog::~Dialog(void)
{
}

//получение события
void Dialog::GetEvent(TEvent &event)
{
	string OpInt = "m+-sqz"; //строка содержит коды операций
	string s;
	string param;
	char code;
	cout << "--- Меню ---" << endl;
	cout << "m	- создать группу" << endl;
	cout << "+	- добавить объект в группу" << endl;
	cout << "-	- удалить объект из группы" << endl;
	cout << "s	- показать всю группу" << endl;
	cout << "z	- показать информацию об элементе с номером k" << endl;
	cout << "q	- конец работы" << endl << endl;
	cout << '>';
	cin >> s;	//считываем строку с командой и параметрами
	code = s[0];	//первый символ строки - команда
	//если строка из кодов операций содержит этот символ, то переходим к обработке операций
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
			//создать группу
			case 'm':
				event.command = cmMake; 
			break;
			//добавить объект в группу
			case '+': 
				event.command = cmAdd; 
			break;
			//удалить объект из группы
			case '-': 
				event.command = cmDel; 
			break;
			//вывести информацию об элементе группы
			case 'z': 
				event.command = cmShowItemK; 
			break; 
			//просмотр группы
			case 's': 
				event.command = cmShow; 
			break;
			//конец работы
			case'q': 
				event.command = cmQuit; 
			break;
		}
		//выделяем параметры команды, если они есть
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());//преобразуем парметр в число
			event.a = A;//записываем в сообщение
		}
	}
	else event.what = evNothing;//пустое событие
}

int Dialog::Execute()
{
	TEvent event;
	do{
		EndState = 0;
		GetEvent(event); //получить событие
		HandleEvent(event); //обработать событие
	} while (!Valid());
	return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0) 
		return 0;
	else 
		return 1;
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;//пустое событие
}

void Dialog::EndExec()
{
	EndState = 1;
}

//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://создание группы
			size = event.a; //размер группы
			beg = new Object*[size];//выделяем память под массив указателей
			cur = 0; //текущая позиция
			cout << "Пустая группа размером " << event.a << " создана.\n";
			ClearEvent(event);//очищаем событие
			break;
		case cmAdd://добавление
			Add();
			ClearEvent(event);
			break;
		case cmDel:Del(); //удаление
			ClearEvent(event);
			break;
		case cmShow:Show(); //просмотр
			ClearEvent(event);
			break;
		case cmShowItemK: ShowItemK(event); //просмотр инфы элемента с номером k
			ClearEvent(event);
			break;
		case cmQuit:EndExec(); //выход
			ClearEvent(event);
			break;
		};
	};
}