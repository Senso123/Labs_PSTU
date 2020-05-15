#include "Print.h"

Print::Print(void)
{
	name = "";
	autor = "";
}
//деструктор
Print::~Print(void)
{
}
//констрктор с параметрами
Print::Print(string N, string A)
{
	name = N;
	autor = A;
}
//конструктор копирования
Print::Print(const Print& print)
{
	name = print.name;
	autor = print.autor;
}

//селекторы
void Print::Set_name(string N)
{
	name = N;
}
void Print::Set_autor(string A)
{
	autor = A;
}

//оператор присваивания
Print& Print::operator=(const Print&p)
{
	if (&p == this)
		return *this;
	name = p.name;
	autor = p.autor;
	return *this;
}

//метод для просмотра атрибутов
void Print::Show()
{
	cout << "\nНазвание: " << name;
	cout << "\nАвтор: " << autor;
	cout << "\n";
}

//метод для ввода значений атрибутов
void Print::Input()
{
	cout << "\nНазвание: "; cin >> name;
	cout << "\nАвтор: "; cin >> autor;
}

void Print::HandleEvent(const TEvent&e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmShowItemK: Show();
			break;
		}
	}
}
