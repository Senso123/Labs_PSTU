#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct tree
{
	double key;//�������������� ����
	tree *left;//����� ������ ���������
	tree *right;//����� ������� ���������
};

vector<double> ans; //���������� ���������� ������, � ������� ������ ��� ��������

//���������� ������ ������
tree* first(double d)//������������ ������� �������� ������
{
	tree* p = new tree;
	p->key = d;
	p->left = 0;
	p->right = 0;
	return p;
}
//���������� �������� d � ������ ������
tree* Add(tree *root, double d)
{
	tree* p = root;//������ ������
	tree* r = NULL;
	//���� ��� �������� ������������� �������� d � ������
	bool ok = false;
	while (p && !ok)
	{
		r = p;
		if (d == p->key)
			ok = true;//������� ��� ����������
		else
			if (d < p->key)
				p = p->left;//����� � ����� ���������
			else 
				p = p->right;//����� � ������ ���������
	}
	if (ok) 
		return p;//�������, �� ���������
	//������� ����
	tree* New_point = new tree();//�������� ������
	New_point->key = d;
	New_point->left = 0;
	New_point->right = 0;
	// ���� d < r->key, �� ��������� ��� � ����� ���������
	if (d < r->key)
		r->left = New_point;
	// ���� d > r->key, �� ��������� ��� � ������ ���������
	else 
		r->right = New_point;
	return New_point;
}

//���������� �������� ����������������� ������
tree* Tree(int n, tree* p)
{
	tree*r;
	int nl, nr;
	//r = p;
	if (n == 0) 
	{ 
		p = NULL; 
		return p; 
	}
	nl = n / 2;
	nr = n - nl - 1;
	r = new tree;
	cout << ">";
	cin >> r->key;
	ans.push_back(r->key);
	r->left = Tree(nl, r->left);
	r->right = Tree(nr, r->right);
	p = r;
	return p;
}

//����� ������������ �������� � ������
void Min(tree*p, double& m)
//����� ����� �������
{
	if (p)
	{
		if (p->key < m)
			m = p->key;
		Min(p->left, m);//������� � ������ ���������
		Min(p->right, m);//������� � ������� ���������
	}
}

//������ ������
void PrintTree(tree* tr, int r)
{
	if (tr != NULL)
	{
		PrintTree(tr->right, r + 5);
		for (int i = 0; i < r; i++)
			cout << " ";
		cout << tr->key << endl;
		PrintTree(tr->left, r + 5);
	}
}
