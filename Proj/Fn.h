#pragma once
#include <string>
#include <vector>
using namespace std;

typedef struct Numb
{
	unsigned long long phone : 44;
	unsigned long long Plus : 1;
}Number;

struct Book
{
	Number tel;
	char Name[39];
};
void TrToBin(unsigned int a); // ќбъ€вление функции в заголовочном файле Fn.h
int CheckStr(char * a, char * b, unsigned int *ch); //ќбъ€вление функции проверки строки
void Table(unsigned int *count, unsigned int*count2, unsigned int * ch); //ќбъ€вление функции вывода двоичных чисел в виде таблицы
void cleanArr(char *a); //‘унци€ очистки массива
int checknumb(char* b);
int NumberIn(Number&, unsigned int * );
void TelTable(Book*, unsigned int*, unsigned int);


//l5

class Nomer {
protected:
	unsigned long long num : 44;
	unsigned long long plus : 1;
public:
	Nomer(unsigned long long num, unsigned long long plus) : num(num), plus(plus ? 1 : 0) {}
	Nomer() : num(0), plus(0) {}
	~Nomer() {};
};

class Kniga : Nomer{
protected:
	string name;
public:
	int write();
	int write2(unsigned int *);
	void print(unsigned int *);
	Kniga(){}
	Kniga(const char* name, unsigned long long num, unsigned long long plus): name(name), Nomer(num,plus){};
	~Kniga() {};
};

void Tabl(vector<Kniga>, unsigned int, unsigned int*);