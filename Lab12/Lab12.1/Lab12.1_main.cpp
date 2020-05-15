#include <iostream>
#include <map>
#include <time.h>
using namespace std;

typedef map<int, int> TMap;//���������� ��� ��� ������ �� �������� (���� ����-��������)
typedef TMap::iterator it;//��������

//������� ��� ������������ �������
TMap make_map(int n)
{
	srand(time(NULL));
	TMap m;//������ �������
	for (int i = 0; i < n; i++)
	{
		//���������� ��������� �����
		float a = rand() / 100 - 1;
		//������� ���� � ��������� �� � �������
		m.insert(make_pair(i, a));
	}
	return m;//���������� ������� ��� ��������� ������ �������
}
//������� ��� ������ �������
void print_map(TMap m)
{
	cout << "\n";
	//�������� ���������� ������� � ������� ���������
	for (it it2 = m.begin(); it2 != m.end(); it2++)
	{
		cout << "<" << it2->first << ", " << it2->second << ">  ";
	}
	cout << endl;
}

//����� ������������� ��������
int find_max(TMap m)
{
	it it2 = m.begin();
	int max = it2->second;
	for (it2 = m.begin(); it2 != m.end(); it2++)
	{
		if (it2->second > max)
			max = it2->second;
	}
	return max;
}

//���������� �������� ��������
int find_mean(TMap m)
{
	int sum = 0;
	for (it it2 = m.begin(); it2 != m.end(); it2++)
	{
		sum += it2->second;
	}
	return(sum / m.size());
}

//������� �� �������� �������
void add_map(TMap &m, int item, int pos)
{
	m.insert(make_pair(pos, item));
}

//�������� ���������
void delete_from_map(TMap &m, int item)
{
	it current, j; //������ ��� ���������
	j = m.begin(); //������ �������
	int k = m.size(); //������ �������
	for (int i = 0; i < k; i++) //� ����� �������� � �����������
	{
		current = j; //��������� � current ��������� �� ������� �������
		j++; //������������ j �� ��������� �������
		if ((current->second) == item) //���� ����� ���, ������� ���� �������, �� �������.
			m.erase(current);			//���� �������� ����, ��� �� ������ ���������. 
		//����� ������� �� ������� � �������� ��������
	}
}

//���������� ���� ���������
void add(TMap &m, int item)
{
	for (it it2 = m.begin(); it2 != m.end(); it2++)
		it2->second = it2->second + item;
}

void main()
{
	int n;
	cout << "N: "; 
	cin >> n;//���������� ���������
	TMap m = make_map(n);//������� �������
	print_map(m);//���������� �������
	cout << endl;

	//���������� ������������� �������� � ����� ����������
	int maxItem = find_max(m);
	cout << "Max: " << maxItem << endl;
	//��������� �� �������, ������ ������� �������, ����� ��� �������������� ���������� ������� ������� �������� � �����
	add_map(m, maxItem, m.size()); 
	cout << "Result: ";
	print_map(m);
	cout << endl;

	//�������� ��������� � �������� ��������
	int key;
	cout << "Value for delete: ";
	cin >> key;
	delete_from_map(m, key);
	cout << "Result: ";
	print_map(m);
	cout << endl;

	//���������� � ������� �������� �������� ���������������
	int srednee = find_mean(m);
	cout << "Srednee: " << srednee << endl;
	add(m, srednee);
	cout << "Result: ";
	print_map(m);
	cout << endl;

	system("pause");
}