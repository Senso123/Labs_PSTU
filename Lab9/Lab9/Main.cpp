#include "Vector.h"
#include <iostream>
using namespace std;

void main()
{
	//�������������� ����
	try
	{
		cout << "Razmer vectora? ";
		int s;
		cin >> s;
		Vector x(s);//������ �� s ���������
		cout << x;//������ ������� �

		cout << "Nomer? ";
		int i;
		cin >> i;
		//����� �������� � ������� i, ���� ����� ������ ������� ������� ��� ������ 0, ��
		//������������ �������������� ��������
		cout << x[i] << endl;

		x--; // ���� ������ ����� ������, �� �������������� ��������
		cout << "x--: " << x;

		--x;  //���� y ����� ������, �� ������������� ����������
		cout << "--x: " << x;

		cout << "Size x = " << x() << endl;
	}
	//���������� ����������
	catch (int e)
	{
		cout << "ERROR " << e << "!!!" << endl;
	}//��������� �� ������
	catch (...)   //���� � ������� ����������, �� ���� �������� ��� ����������, �� �������� � ����� catch(), ��������� ����. 
		//� ����� ������ ���� ������� ����������, ��� ����� throw �������� ������ (string)
	{
		cout << "ERROR!!!" << endl;
	}
	system("pause");
}