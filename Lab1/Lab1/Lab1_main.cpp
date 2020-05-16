#include <iostream>
#include "Range.h"
using namespace std;

Range makeRange(float f, float s)
{
	Range t;		//������� ��������� ����������
	t.Init(f, s);	//���������������� ���� ���������� � ������� ���������� �������
	return t;		//������� �������� ���������� t
}

void main()
{
	setlocale(LC_ALL, "russian");
	//����������� ���������� � � �
	cout << "------����������------" << endl;
	Range A;
	Range B;
	A.Init(2.9, 5.3);	//������������� ���������� �
	B.Read();		//���� ����� ���������� �
	cout << "A: ";
	A.Show();		//����� �������� ����� ���������� �
	cout << "B: ";
	B.Show();		//����� �������� ����� ���������� �
	//����� ����� ����� �����, ����������� � ������� ������� ipart()
	cout << "A.rangecheck(10.4) = " << A.rangecheck(10.4) << endl;
	cout << "B.rangecheck(3.1) = " << B.rangecheck(3.1) << endl;

	//���������
	cout << "\n------���������------" << endl;
	Range *c = new Range;	//��������� ������ ��� ������������ ����������
	c->Init(7.4, 12.6);	//�������������
	cout << "C: ";
	c->Show();	//����� �������� �����
	cout << "C.rangecheck(5.1) = " << c->rangecheck(5.1) << endl;

	//�������
	cout << "\n------�������------" << endl;
	Range mas[3];//����������� �������
	for (int i = 0; i < 3; i++)
		mas[i].Read();//������ �������� �����
	for (int i = 0; i < 3; i++)
		mas[i].Show(); //����� �������� �����
	for (int i = 0; i < 3; i++)
		cout << "mas[" << i << "].rangecheck(3.0) = " << mas[i].rangecheck(3.0) << endl;

	//������������ ������
	cout << "\n------������������ �������------" << endl;
	Range* p_mas = new Range[3];//��������� ������
	for (int i = 0; i < 3; i++)
		p_mas[i].Read();//������ �������� �����
	for (int i = 0; i < 3; i++)
		p_mas[i].Show();//����� �������� �����
	for (int i = 0; i < 3; i++)
		cout << "p_mas[" << i << "].rangecheck(3.0) = " << p_mas[i].rangecheck(3.0) << endl;

	//����� ������� makeFraction()
	cout << "\n------����� ������� makeRange()------" << endl;
	int y;
	int z;
	cout << "First: ";
	cin >> y;
	cout << "Second: ";
	cin >> z;
	//���������� F ����������� � ������� ������� makeRange()
	Range F = makeRange(y, z);
	F.Show();
	system("pause");
}