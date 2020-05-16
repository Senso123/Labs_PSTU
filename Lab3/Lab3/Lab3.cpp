#include "Time.h" 
#include <iostream> 
using namespace std;

void main()
{
	
	Time a;//конструктор без параметров 
	Time b; //конструктор без параметров 
	Time c; //конструктор без параметров 
	Time min;
	Time sec;


	cin>>a;//ввод переменной 
	cin>>b;//ввод переменной

	//++a;//префиксная операция инкремент 
	
	c = a + b;//сложение и постфиксная операция инкремент 

	cout << "vremya1: " << a << endl;//вывод переменной

	cout<<"vremya2: "<<b<<endl; //вывод переменной 

	
    cout<<"pribavlenie sekund: "<<c<<endl; //вывод переменной

	//cout<<"sravnenie: " <<endl; //вывод переменной 
	
	
}

