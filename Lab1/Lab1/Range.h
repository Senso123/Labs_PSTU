#pragma once
struct Range
{
	float first;			//����� �������
	float second;			//������ �������
	void Init(float, float);	//������������� ������� ���������
	void Read();			//����� ��� ������ ����� ���������
	void Show();			//����� ��� ������ �� ����� ������� ���������
	bool rangecheck(float x);	//����� ��� ����������� �������������� ����� � ���������
};

