#include <stdio.h>
#include < string.h >
#include <stdlib.h>

void cleanArr(char *a) { //�������� �������
	for ( int i = 0; i < sizeof(a)/sizeof(char); i++ ) {
		*a = '\0';
		a++;
	}
}


void TrToBin(unsigned int a) { // ������� � �������� �����
	unsigned int b, i = 0; //������������� ����������� ���������� b � i, b - ���� �����, i - ������� ��� �����
	printf("\t");
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
			printf(" ");
		}
	} while (i <= 31); // ���� i ������ ��� ����� 31
}

void Table(unsigned int* count, unsigned int* count2) {
	unsigned int cunt = 1; //���������� ��� ������ ����������� ������ �����
	printf("  �\t�����\t\t\t�������� ���\n"); //������������ �����
	do { //���� do while
		printf("  %d\t%d\t\t", cunt, *count2); //������ ����� ��������� ����������� ������ ����� � ���� �����
		TrToBin(*count2); //����� ������� ��� �������� ����� � ��������, ����� ����� ���������� ����� � ���� �������
		printf("\n"); //������� �� ����� ������
		cunt++; //�������� ��� ����� ����������� ������ � ������������� � �������
		count2++; //������� �� �����, � ������� ����� �����, ������� ���� ������������
	} while ( *count2 != '\0' && cunt < *count );
}

int CheckStr(char  *a, char * b) {
	size_t ch = 0; //���������� � ������������� ����������, ������� ��� ���������� ��������
	do { //������ �����
		ch++; //������ �������� ���������� 1
		if ( *a >= '0' && *a <= '9' ) { // ��������, ��� � ��������� ������ ������ �����
			*b = *a;
			a++; //��������� � ��������� ������ �������
			b++; //��������� � ��������� ������ �������
		}
		else {
			a++;
			ch--;
			//printf("� ����� ���� ������ �������, �� �� �� ��� �������!'\n");�
		}
	} while ( *a != '\0' );//���� ���� �� ����� ������� �� ����� \0
	if ( ch <= 10 ) { //������� ���������� ���� � �����
		return 0;//������� 0 � ������ ���� ����� ��������� ����������
	}
	else {
		return -1; //� ������ ���� ����� ������, ���������� -1
	}
}