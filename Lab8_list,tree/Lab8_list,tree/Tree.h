#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct tree
{
	double key;//информационное поле
	tree *left;//адрес левого поддерева
	tree *right;//адрес правого поддерева
};

vector<double> ans; //глобальная переменная вектор, в которую сложим все элементы

//построение дерева поиска
tree* first(double d)//формирование первого элемента дерева
{
	tree* p = new tree;
	p->key = d;
	p->left = 0;
	p->right = 0;
	return p;
}
//добавление элемента d в дерево поиска
tree* Add(tree *root, double d)
{
	tree* p = root;//корень дерева
	tree* r = NULL;
	//флаг для проверки существования элемента d в дереве
	bool ok = false;
	while (p && !ok)
	{
		r = p;
		if (d == p->key)
			ok = true;//элемент уже существует
		else
			if (d < p->key)
				p = p->left;//пойти в левое поддерево
			else 
				p = p->right;//пойти в правое поддерево
	}
	if (ok) 
		return p;//найдено, не добавляем
	//создаем узел
	tree* New_point = new tree();//выделили память
	New_point->key = d;
	New_point->left = 0;
	New_point->right = 0;
	// если d < r->key, то добавляем его в левое поддерево
	if (d < r->key)
		r->left = New_point;
	// если d > r->key, то добавляем его в правое поддерево
	else 
		r->right = New_point;
	return New_point;
}

//построение идеально сбалансированного дерева
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

//поиск минимального элемента в дереве
void Min(tree*p, double& m)
//обход слева направо
{
	if (p)
	{
		if (p->key < m)
			m = p->key;
		Min(p->left, m);//переход к левому поддереву
		Min(p->right, m);//переход к правому поддереву
	}
}

//печать дерева
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
