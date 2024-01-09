#pragma once
#include <string>
#include <vector>
using namespace std;

typedef struct Numb
{
	unsigned long long phone : 44; //����������� ������� � ������
	unsigned long long Plus : 1;
}Number;

struct Book
{
	Number tel;
	char Name[39];
};
void TrToBin(unsigned int a); // ���������� ������� � ������������ ����� Fn.h
int CheckStr(char * a, char * b, unsigned int *ch); //���������� ������� �������� ������
void Table(unsigned int *count, unsigned int*count2, unsigned int * ch); //���������� ������� ������ �������� ����� � ���� �������
void cleanArr(char *a); //������ ������� �������
int checknumb(char* b);
int NumberIn(Number&, unsigned int * );
void TelTable(Book*, unsigned int*, unsigned int);


//l5

class Nomer {
protected:
	unsigned long long num : 44; //���������� �������� 44 ���� ��� �������� ������ ��������
	unsigned long long plus : 1; //���������� ��� ������� ������� +
public:
	Nomer() {} //�����������
	~Nomer() {}; //����������
};

class Kniga : Nomer{ //�����, �������������� �� ������ Nomer
protected:
	string name; //�������� �� ������ ������� ���������� name ���� string
public:
	int write(); //������� ������ ������ ��������
	int write2(unsigned int *); //������� ������ �����
	void print(int *); //������� ������ ����� � ������ ��������
	int sort(vector<Kniga>*);
	Kniga(){} //�����������
	~Kniga() {}; //����������
};

void Tabl(vector<Kniga>*, unsigned int, int); //���������� ������� Tabl, ��������������� ��� �������� �������