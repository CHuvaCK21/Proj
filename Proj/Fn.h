#pragma once

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