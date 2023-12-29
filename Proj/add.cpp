#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locale.h"
#include <vector>
#include "Fn.h"

void TelTable(Book* phr, unsigned int *ch, unsigned int c) {
	unsigned int cunt = 0; //���������� ��� �������
	printf("\t\t\t\t\t\t �     ��� ��������\t    ����� ��������\n"); //���������
	do {
		printf("\t\t\t\t\t\t %d ", cunt+1); //����� ����������� ����� ������ ��������
		printf("    %s", phr[cunt].Name); //����� ����� ��������
		for ( unsigned int i = 0; i < ( 21 - *ch ); i++ ) { //����������� ��������� ����� � �������
			printf("."); //������ ����� ��� ��������
		}
		ch++; //������� �� ������� ch ��� ��������� ���������� ���������� ���� � ������ ��������
		printf("%c", phr[cunt].tel.Plus ? '+' : ' '); //����� ����� ���� ���� ������� �������
		printf("%lld\n", phr[cunt].tel.phone); //����� ������ ��������
		cunt++;//����������� 1 � ������ �������� �����
	} while ( cunt < c); //���� ������� ����� ������ ��� ���������� ��������� ������� � ����
}

void Tabl(vector<Kniga> tk, unsigned int in, unsigned int *ch) {
	unsigned int c = 1;
	cout << "� ��� �������� \t\t����� ��������"<<endl;
	do {
		for ( auto i = tk.begin(); i != tk.end(); i++ ) {
			cout << c<<" ";
			i->print(ch);
			c++;
			ch++;
		}
	} while (c < in);
}
int NumberIn(Number& phTel, unsigned int *ch) //������� ����� ������ ��������
{
	printf("������ ����� ��������: "); //������� ������ ����� ��������
	char a[39], b[39]; //2 �������, � ���� ����� ������� �����, � ������ ����� ������� ����� ������������ ��� ���� � �.�
	scanf_s("%s", a, 39); //���� � ������ a
	if ( a[0] == '+' ) //���� ������ ������ �������� +
	{
		if ( CheckStr(&a[1], b, ch) == 0 ) { //���� ������ ������ ��� +, �� �������� � ������� �������� ������ �������� ������� �� ������� �������� �������
			phTel.Plus = 1; //���� ������ ������� +, �� ���������� Plus ����� ��������� ����������� 1
			phTel.phone = atoll(b); //����� ����������� ������ ������ �������� � ��������� ��� � ������ b, �� �������� atoll ��������� ��� � int � ����������� ���������� phone ����� ���������
		}
		else {
			printf("����� ��������� �����������"); //���� checkstr ������ �� 0, �� ������
			return -1;
		}
	}
	else
	{
		if ( CheckStr(a, b, ch) == 0 ) { //���� ������ ������ �� +, �� �������� �������� ������ � ������� �������� �������
			phTel.Plus = 0; //����� ����������� ���������� Plus ��������� 1 �.� ����� ���
			phTel.phone = atoll(b); //������� ������������� ����� � int 
		}
		else {
			printf("����� ��������� �����������"); //���� ����� ������ 13, �� ������ ������
			return -1;
		}
	}
	return 0; //� ������ ���� ������ �� ����, �� ���������� 0
}

int checknumb(char * b) {
	unsigned int ch5 = 0; //���������� ���������� ��� ������ ������ 9�� ����� ����� � ��� int

		for ( int i = 0; i < 9; i++ ) { //� ����� �������� �� ����� ������ � ���������� � ���� ch5 ������������ ����� ��� ���������� �������
			if ( *b != '\0' ) {
				ch5 = ch5 * 10 + ( *b - '0' );
				b++;
			}
		}

		if ( ch5 > 429496729 ) { //���������� ��������, ���� ������ 9 ������ ������������� ����� ������ ��� 429496729, �� ���������� -1
			return -1;
		}
		else if(ch5 == 429496729) { //����� ���� ����� ������ 429496729, �� ��������� �� ���������, ���� ����� �����, �� ��������� ��������� ������� �� �� ������ 5 �� ��� ���
			if ( *b > '5' ) {
				return -1; //������� -1 ���� ��������� ������� ������ 5
			}
			else { //����� ���������� 0
				return 0;
			}
		}
		else { //���� ����� �� ����� 429496729, �� ������������� ���������� 0
			return 0;
		}
}

void cleanArr(char *a) { //�������� �������
	for ( int i = 0; i < 32; i++ ) {
		*a = '\0';
		a++;
	}
}


void TrToBin(unsigned int a) { // ������� � �������� �����
	unsigned int b, i = 0; //������������� ����������� ���������� b � i, b - ���� �����, i - ������� ��� �����

	do{ // ������ �����: ������ ���{}����(�������);
		b = 1 << (31 - i); // �������� ������ �������� ���� ����� �� ���� ��� ������
		if (b & a) { // ���������� ����������
			printf("1"); // ���� ���������� � ����� 1, �� ����� 1
		}
		else {
			printf("0"); // ����� ���������� � ����� 0, �� ����� 0
		}
		i++; //������� �����, ���������� ������ �������� �������

		if ( i % 4 == 0 ) {
			printf(" "); //������ �������� ����� ������ 4 �����
		}
	} while (i <= 31); // ���� i ������ ��� ����� 31
}

void Table(unsigned int* count, unsigned int* count2, unsigned int *ch) {
	unsigned int cunt = 1; //���������� ��� ������ ����������� ������ �����
	printf("  �\t�����\t\t\t�������� ���\n"); //������������ �����

	do { //���� do while
		printf("  %d\t%lu", cunt, *count2); //������ ����� ��������� ����������� ������ ����� � ���� �����
		for ( unsigned int i = 0; i < (24-*ch); i++ ) { //����������� ��������� ����� � �������
			printf("."); //������ ����� ��� ��������
		}
		ch++; //������� � ���������� ������� � ����������� ���� � �����
		TrToBin(*count2); //����� ������� ��� �������� ����� � ��������, ����� ����� ���������� ����� � ���� �������
		printf("\n"); //������� �� ����� ������
		cunt++; //�������� ��� ����� ����������� ������ � ������������� � �������
		count2++; //������� �� �������, � ������� ����� �����, ������� ���� ������������
	} while ( *count2 != '\0' && cunt < *count ); //���� �� �� ������ �� ����� ������� � ������� � ���� �� ������ �� ����� ���������� �����
}

int CheckStr(char  *a, char * b, unsigned int *ch) {
	do { //������ �����
		(*ch)++; //������ �������� ���������� 1
		if ( *a >= '0' && *a <= '9' ) { // ��������, ��� � ��������� ������ ������ �����
			*b = *a; //����������� ������ ������� b �������� ������� a ���� �� �������� ������
			a++; //��������� � ��������� ������ �������
			b++; //��������� � ��������� ������ �������
		}
		else {
			a++; //��������� � ��������� ������ �������
			(*ch)--; //���� ������� �� ���������, ��  ������ �� ������������� � ���������� ����� �����������
			//printf("� ����� ���� ������ �������, �� �� �� ��� �������!'\n");�
		}
	} while ( *a != '\0' );//���� ���� �� ����� ������� �� ����� \0

	if ( *ch <= 13 && *ch > 0) { //�������� �� ���������� ����� � �����
		return 0;//������� 0 � ������ ���� ����� ��������� ����������
	}
	else {
		( *ch ) = 0; //���� ����� ������������ ����������, �� ����������� ���������� ch ����, ����� � ��������� ��������� �� �� ����������� ������������
		return -1; //� ������ ���� ����� ������, ���������� -1
	}
}