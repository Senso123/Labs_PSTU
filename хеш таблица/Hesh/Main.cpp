#include <iostream>;
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

const double A = 0.6; //используется в хеш-функции
const int M = 300; //размер хеш-таблицы
const int c = 1; //используется в формуле при разрешении коллизий

//массивы для случайного заполнения полей структуры Person
static const char bigLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char smallLetters[] = "abcdefghijklmnopqrstuvwxyz";
static const char arrayNum[] = "0123456789";

//информационная структура об элементе
struct Person
{
	string name;		//фио
	string passport;	//номер паспорта
	string address;		//адрес
};

//структура связного списка (цепочки), которая хранит информацию об элементе и указатель на следующий элемент
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

//получение строки, сгенерированной случайным образом
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

//получение номера паспорта (6 цифр) случайным образом
string getRandomPassport()
{
	string s = "";
	for (int i = 0; i < 6; ++i) {
		s += arrayNum[rand() % (sizeof(arrayNum) - 1)];
	}
	return s;
}

//создание нового элемента списка
Node* newNode()
{
	Node* d = new (Node);
	d->info.name = getRandomStr(8);
	d->info.address = getRandomStr(12);
	d->info.passport = getRandomPassport();
	d->next = NULL;
	return d;
}

//создание пустого узла
Node* emptyNode()
{
	Node* d = new (Node);
	d->next = NULL;
	return d;
}

//создание нового узла
Node* createNewNode()
{
	Node* d = new (Node);
	d->next = NULL;
	cout << "Имя: ";
	cin >> d->info.name;
	cout << "Номер паспорта: ";
	cin >> d->info.passport;
	cout << "Адрес: ";
	cin >> d->info.address;
	return d;
}

//функция для вычисления индекса в хеш-таблице
int getIndex(string key)
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++)
		sum += key.at(i) - '0'; //сразу же переводим символ цифры в Int
	double k = sum * A;
	double a = modf(k, &a);
	double rez;
	modf(M * a, &rez);
	return rez;
}

//вставка в хеш-таблицу
int hashInsert(Node **hash, Node* d)
{
	int i = 0; //номер очередной попытки вставить запись
	int index = getIndex(d->info.passport);
	//если ячейка массива пустая, то просто вставляем туда элемент
	if (hash[index] == NULL)
		hash[index] = d;
	else //иначе нужно разрешить коллизию
	{
		i++;
		//берём начало списка
		Node* head = hash[index];
		//доходим до его конца
		while (head->next != NULL)
			head = head->next;
		//добавляем новый элемент в конец списка
		head->next = d;
	}
	return i;
}

//поиск в хеш-таблице
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
		return NULL; //если дошли до этой строки, значит так и не нашли элемент с нужным номером паспорта
	}
}

//печать содержимого элемента на экран
void printNode(Node* d)
{
	cout << "Имя: " << d->info.name << endl;
	cout << "Номер паспорта: " << d->info.passport << endl;
	cout << "Адрес: " << d->info.address << endl;
}

//удаление элемента из хеш-таблицы
bool deleteHash(Node **hash, string passport)
{
	int index = getIndex(passport);
	if (hash[index] == NULL)
		return false;
	else
	{
		Node* head = hash[index]; //получили указатель на начало списка, в котором возможно содержится удаляемый элемент
		if (head->info.passport == passport) //если удалить надо первый элемент
		{
			Node* q = head;
			head = head->next;
			hash[index] = head;
			delete q;
			return true;
		}
		while (head->next != NULL) //если дошли до сюда, значит удаляемый элемент не в начале списка
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
		if (head->info.passport == passport) //если дошли до сюда, то удаляемый элемент возможно находится в конце списка
		{
			Node* q = head;
			delete q;
			return true;
		}
		return false; //если дошли до этой строки, значит так и не нашли элемент с нужным номером паспорта и ничего не удалили
	}
}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "russian");
	//создаём динамический массив размером 300, содержащий указатели на структуру Node
	Node **hash = new Node*[M];
	Node *p;
	//заполняем хеш-таблицу пустыми значениями, чтобы можно было распознать пустые ячейки
	for (int i = 0; i < M; i++)
		hash[i] = NULL;
	int answer;
	do
	{
		system("cls");
		cout << "----- МЕНЮ -----" << endl;
		cout << "1 - сформировать новую хеш-таблицу" << endl;
		cout << "2 - считать таблицу из файла" << endl;
		cout << "3 - сохранить таблицу в файл" << endl;
		cout << "4 - добавить новый элемент" << endl;
		cout << "5 - найти элемент по ключу" << endl;
		cout << "6 - удалить элемент по ключу" << endl;
		cout << "0 - выход" << endl;
		cout << "Ответ: ";
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			//проходим по всем элементам таблицы, по всем спискам и очищаем
			clearHash(hash);
			cout << "Количество элементов: ";
			int count;
			cin >> count;
			//теперь надо заполнить хеш-таблицу по всем правилам, подсчитав количество коллизий
			int countCollision = 0;
			for (int i = 0; i < count; i++)
			{
				p = newNode();
				countCollision = countCollision + hashInsert(hash, p);
			}
			cout << "Таблица сформирована. Всего коллизий: " << countCollision << endl;
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
			cout << "Таблица успешно считана." << endl;
			system("pause");
		}
		break;
		case 3:
		{
			ofstream file;
			file.open("HeshTable.txt");
			file.clear();
			bool firstRow = false; //флаг на то, записали ли первую строку
			//идём по массиву
			for (int i = 0; i < M; i++)
			{
				//если элемент массива не пустой, нужно пройти по всему списку, привязанному к нему
				if (hash[i] != NULL)
				{
					Node* head = hash[i];
					while (head != NULL)
					{
						if (!firstRow) //если первая строка ещё не записана, то нужно писать БЕЗ перевода каретки
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
			cout << "Таблица успешно выгружена в файл" << endl;
			system("pause");
		}
		break;
		case 4:
		{
			p = createNewNode();
			int c = hashInsert(hash, p);
			cout << "Элемент добавлен. Коллизий при вставке: " << c << endl;
			system("pause");
		}
		break;
		case 5:
		{
			cout << "Введите номер паспорта искомого элемента: ";
			string s;
			cin >> s;
			p = findHash(hash, s);
			if (p == NULL)
				cout << "Элемент не найден!" << endl;
			else
			{
				cout << "Элемент найден: " << endl;
				printNode(p);
			}
			system("pause");
		}
		break;
		case 6:
		{
			cout << "Введите номер паспорта искомого элемента для удаления: ";
			string s;
			cin >> s;
			bool del = deleteHash(hash, s);
			if (!del)
				cout << "Элемент не найден!" << endl;
			else
				cout << "Элемент найден и успешно удалён." << endl;
			system("pause");
		}
		break;
		case 0:
			clearHash(hash); //освободим память, прежде чем завершать программу
		break;
		default:
			break;
		}
	} while (answer != 0);
	system("pause");
}

