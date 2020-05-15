#include "Print.h"

Print::Print(void)
{
	name = "";
	autor = "";
}
//����������
Print::~Print(void)
{
}
//���������� � �����������
Print::Print(string N, string A)
{
	name = N;
	autor = A;
}
//����������� �����������
Print::Print(const Print& print)
{
	name = print.name;
	autor = print.autor;
}

//���������
void Print::Set_name(string N)
{
	name = N;
}
void Print::Set_autor(string A)
{
	autor = A;
}

//�������� ������������
Print& Print::operator=(const Print&p)
{
	if (&p == this)
		return *this;
	name = p.name;
	autor = p.autor;
	return *this;
}

//����� ��� ��������� ���������
void Print::Show()
{
	cout << "\n��������: " << name;
	cout << "\n�����: " << autor;
	cout << "\n";
}

//����� ��� ����� �������� ���������
void Print::Input()
{
	cout << "\n��������: "; cin >> name;
	cout << "\n�����: "; cin >> autor;
}

void Print::HandleEvent(const TEvent&e)
{
	if (e.what == evMessage)//�������-���������
	{
		switch (e.command)
		{
		case cmShowItemK: Show();
			break;
		}
	}
}
