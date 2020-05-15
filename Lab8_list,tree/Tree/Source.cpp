#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

struct Node
{
	int key;
	Node *right, *left;
};

typedef Node *KNode;
const int n = 10;

KNode maketree(int mass[], int *from, int n)
{
	KNode tree;
	if (n == 0) return NULL;
	int nr, nl;
	tree = new Node;
	tree->key = mass[*from];
	(*from)++;
	nl = n / 2;
	nr = n - nl - 1;
	tree->left = maketree(mass, from, nl);
	tree->right = maketree(mass, from, nr);
	return tree;
}

void PrintTree(KNode tree, int r)
{
	if (tree != NULL)
	{
		PrintTree(tree->right, r + 5);
		for (int i = 0; i < r; i++)
			printf(" ");
		printf("%d\n", tree->key);
		PrintTree(tree->left, r + 5);
	}
}

void main()
{
	srand(time(NULL));
	int mass[n], i;
	for (int i = 0; i<n; i++)
		mass[i] = 0;
	for (int i = 0; i<n; i++)
		mass[i] = ((rand() % 9) + 1) * 10 + rand() % 10;
	/*for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(mass[i]=mass[j])
	{
	mass[j]=((rand()%9)+1)*1000+rand()%100;
	j=i+1;
	}*/
	printf("Initial sequence\n");
	for (int i = 0; i<n; i++)
		printf("%i ", mass[i]);
	printf("\n");
	KNode Tree;
	i = 0;
	Tree = maketree(mass, &i, n);
	PrintTree(Tree, 0);
//	getch();
	system("pause");
}