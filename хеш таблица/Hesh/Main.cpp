#include <iostream>;
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

const double A = 0.6; //������������ � ���-�������
const int M = 300; //������ ���-�������
const int c = 1; //������������ � ������� ��� ���������� ��������

//������� ��� ���������� ���������� ����� ��������� Person
static const char bigLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char smallLetters[] = "abcdefghijklmnopqrstuvwxyz";
static const char arrayNum[] = "0123456789";

//�������������� ��������� �� ��������
struct Person
{
	string name;		//���
	string passport;	//����� ��������
	string address;		//�����
};

//��������� �������� ������ (�������), ������� ������ ���������� �� �������� � ��������� �� ��������� �������
struct Node
{
	Person info;
	Node* next;
};

void clearHash(Node **hash)
{
	for (int i = 0; i < M; i++)
	{
		if (hash[i] != NULL)
		{
			Node* head = hash[i];
			Node* q;
			while (head != NULL)
			{
				q = head;
				head = head->next;
				delete q;
			}
			hash[i] = NULL;
		}
	}
}

//��������� ������, ��������������� ��������� �������
string getRandomStr(const int len)
{
	string s;
	int k = rand() % (sizeof(bigLetters) - 1);
	s = bigLetters[k];
	for (int i = 1; i < len; ++i) {
		k = rand() % (sizeof(smallLetters) - 1);
		s += smallLetters[k];
	}
	return s;
}

//��������� ������ �������� (6 ����) ��������� �������
string getRandomPassport()
{
	string s = "";
	for (int i = 0; i < 6; ++i) {
		s += arrayNum[rand() % (sizeof(arrayNum) - 1)];
	}
	return s;
}

//�������� ������ �������� ������
Node* newNode()
{
	Node* d = new (Node);
	d->info.name = getRandomStr(8);
	d->info.address = getRandomStr(12);
	d->info.passport = getRandomPassport();
	d->next = NULL;
	return d;
}

//�������� ������� ����
Node* emptyNode()
{
	Node* d = new (Node);
	d->next = NULL;
	return d;
}

//�������� ������ ����
Node* createNewNode()
{
	Node* d = new (Node);
	d->next = NULL;
	cout << "���: ";
	cin >> d->info.name;
	cout << "����� ��������: ";
	cin >> d->info.passport;
	cout << "�����: ";
	cin >> d->info.address;
	return d;
}

//������� ��� ���������� ������� � ���-�������
int getIndex(string key)
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++)
		sum += key.at(i) - '0'; //����� �� ��������� ������ ����� � Int
	double k = sum * A;
	double a = modf(k, &a);
	double rez;
	modf(M * a, &rez);
	return rez;
}

//������� � ���-�������
int hashInsert(Node **hash, Node* d)
{
	int i = 0; //����� ��������� ������� �������� ������
	int index = getIndex(d->info.passport);
	//���� ������ ������� ������, �� ������ ��������� ���� �������
	if (hash[index] == NULL)
		hash[index] = d;
	else //����� ����� ��������� ��������
	{
		i++;
		//���� ������ ������
		Node* head = hash[index];
		//������� �� ��� �����
		while (head->next != NULL)
			head = head->next;
		//��������� ����� ������� � ����� ������
		head->next = d;
	}
	return i;
}

//����� � ���-�������
Node* findHash(Node **hash, string passport)
{
	int index = getIndex(passport);
	if (hash[index] == NULL)
		return NULL;
	else
	{
		Node* head = hash[index];
		while (head != NULL)
		{
			if (head->info.passport == passport)
				return head;
			head = head->next;
		}
		return NULL; //���� ����� �� ���� ������, ������ ��� � �� ����� ������� � ������ ������� ��������
	}
}

//������ ����������� �������� �� �����
void printNode(Node* d)
{
	cout << "���: " << d->info.name << endl;
	cout << "����� ��������: " << d->info.passport << endl;
	cout << "�����: " << d->info.address << endl;
}

//�������� �������� �� ���-�������
bool deleteHash(Node **hash, string passport)
{
	int index = getIndex(passport);
	if (hash[index] == NULL)
		return false;
	else
	{
		Node* head = hash[index]; //�������� ��������� �� ������ ������, � ������� �������� ���������� ��������� �������
		if (head->info.passport == passport) //���� ������� ���� ������ �������
		{
			Node* q = head;
			head = head->next;
			hash[index] = head;
			delete q;
			return true;
		}
		while (head->next != NULL) //���� ����� �� ����, ������ ��������� ������� �� � ������ ������
		{
			if (head->next->info.passport == passport)
			{
				Node* q = head->next;
				head->next = head->next->next;
				delete q;
				return true;
			}
			head = head->next;
		}
		if (head->info.passport == passport) //���� ����� �� ����, �� ��������� ������� �������� ��������� � ����� ������
		{
			Node* q = head;
			delete q;
			return true;
		}
		return false; //���� ����� �� ���� ������, ������ ��� � �� ����� ������� � ������ ������� �������� � ������ �� �������
	}
}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "russian");
	//������ ������������ ������ �������� 300, ���������� ��������� �� ��������� Node
	Node **hash = new Node*[M];
	Node *p;
	//��������� ���-������� ������� ����������, ����� ����� ���� ���������� ������ ������
	for (int i = 0; i < M; i++)
		hash[i] = NULL;
	int answer;
	do
	{
		system("cls");
		cout << "----- ���� -----" << endl;
		cout << "1 - ������������ ����� ���-�������" << endl;
		cout << "2 - ������� ������� �� �����" << endl;
		cout << "3 - ��������� ������� � ����" << endl;
		cout << "4 - �������� ����� �������" << endl;
		cout << "5 - ����� ������� �� �����" << endl;
		cout << "6 - ������� ������� �� �����" << endl;
		cout << "0 - �����" << endl;
		cout << "�����: ";
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			//�������� �� ���� ��������� �������, �� ���� ������� � �������
			clearHash(hash);
			cout << "���������� ���������: ";
			int count;
			cin >> count;
			//������ ���� ��������� ���-������� �� ���� ��������, ��������� ���������� ��������
			int countCollision = 0;
			for (int i = 0; i < count; i++)
			{
				p = newNode();
				countCollision = countCollision + hashInsert(hash, p);
			}
			cout << "������� ������������. ����� ��������: " << countCollision << endl;
			system("pause");
		}
		break;
		case 2:
		{
			ifstream  file;
			file.open("HeshTable.txt");
			int i;
			while (!file.eof())
			{
				p = emptyNode();
				file >> i >> p->info.name >> p->info.passport >> p->info.address;
				hashInsert(hash, p);
			}
			file.close();
			cout << "������� ������� �������." << endl;
			system("pause");
		}
		break;
		case 3:
		{
			ofstream file;
			file.open("HeshTable.txt");
			file.clear();
			bool firstRow = false; //���� �� ��, �������� �� ������ ������
			//��� �� �������
			for (int i = 0; i < M; i++)
			{
				//���� ������� ������� �� ������, ����� ������ �� ����� ������, ������������ � ����
				if (hash[i] != NULL)
				{
					Node* head = hash[i];
					while (head != NULL)
					{
						if (!firstRow) //���� ������ ������ ��� �� ��������, �� ����� ������ ��� �������� �������
						{
							file << i << " " << head->info.name << " " << head->info.passport << " " << head->info.address;
							firstRow = true;
						}
						else
							file << endl << i << " " << head->info.name << " " << head->info.passport << " " << head->info.address;
						head = head->next;
					}
				}
			}
			file.close();
			cout << "������� ������� ��������� � ����" << endl;
			system("pause");
		}
		break;
		case 4:
		{
			p = createNewNode();
			int c = hashInsert(hash, p);
			cout << "������� ��������. �������� ��� �������: " << c << endl;
			system("pause");
		}
		break;
		case 5:
		{
			cout << "������� ����� �������� �������� ��������: ";
			string s;
			cin >> s;
			p = findHash(hash, s);
			if (p == NULL)
				cout << "������� �� ������!" << endl;
			else
			{
				cout << "������� ������: " << endl;
				printNode(p);
			}
			system("pause");
		}
		break;
		case 6:
		{
			cout << "������� ����� �������� �������� �������� ��� ��������: ";
			string s;
			cin >> s;
			bool del = deleteHash(hash, s);
			if (!del)
				cout << "������� �� ������!" << endl;
			else
				cout << "������� ������ � ������� �����." << endl;
			system("pause");
		}
		break;
		case 0:
			clearHash(hash); //��������� ������, ������ ��� ��������� ���������
		break;
		default:
			break;
		}
	} while (answer != 0);
	system("pause");
}

