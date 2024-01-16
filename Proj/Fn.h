#pragma once
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct Numb
{
	unsigned long long phone : 44; //Обоснование размера в отчете
	unsigned long long Plus : 1;
}Number;

struct Book
{
	Number tel;
	char Name[39];
};
void TrToBin(unsigned int a); // Объявление функции в заголовочном файле Fn.h
int CheckStr(char * a, char * b, unsigned int *ch); //Объявление функции проверки строки
void Table(unsigned int *count, unsigned int*count2, unsigned int * ch); //Объявление функции вывода двоичных чисел в виде таблицы
void cleanArr(char *a); //Фунция очистки массива
int checknumb(char* b);
int NumberIn(Number&, unsigned int * );
void TelTable(Book*, unsigned int*, unsigned int);


//l5, l6, l7

class Nomer {
protected:
	unsigned long long num : 44; //Переменная размером 44 бита для хранения номера телефона
	unsigned long long plus : 1; //Переменная для наличия символа +
public:
	Nomer() {} //Конструктор
	~Nomer() {}; //Деструктор
};

class Kniga : Nomer{ //Класс, унаследованный от класса Nomer
protected:
	string name; //Закрытая от других функций переменная name типа string
public:
	int write(); //Функция записи номера телефона
	int write2(unsigned int *); //Функция записи имени
	void print(int *); //Функция вывода имени и номера телефона
	bool operator <(Kniga &); // Объявление перегрузки оператора >
	bool operator >=(const char & ); //Объявление перегрузки оператора >=
	bool operator <=(const char&); //Объявление перегрузки оператора <=
	void operator -(const int &); //Объявление перегрузки оператора -
	void search(string, vector<Kniga>, vector<Kniga> *); //Функция поиска
	Kniga(){} //Конструктор
	~Kniga() {}; //Деструктор
};

void Tabl(vector<Kniga>*, unsigned int, int); //Объявление функции Tabl, предназначенная для создания таблицы
int sort(vector<Kniga>&); //Объявление функции сортировки