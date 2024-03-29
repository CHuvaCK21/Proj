#include "../../Proj/Fn.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale.h>

bool Kniga::operator <(Kniga &name2) { //���� ���������� ��������� <
	if (name < name2.name) { //����������� ���� ����
		return true; //���������� true ���� ��������� �������������
	}
	else {
		return false; //����� ���������� false
	}
}
bool Kniga::operator<=(const char &a) { //���� ���������� ��������� <=
	if (name[0] <= a) { //���� ������ ������ ����� � ��������
		return true; //�� ���������� true
	}
	else {
		return false; //����� false
	}
}

bool Kniga::operator>=(const char &a) { //���� ���������� ��������� >=
	if (name[0] >= a) { //���� ������ ������ ����� � ��������
		return true; //�� ���������� true
	}
	else {
		return false; //����� false
	}
}

void Kniga::operator-(const int &n) { //���� ���������� ��������� -
	name[0] = name[0] - n; //�������� n
}

void Kniga::search(string ser, vector<Kniga> let, vector<Kniga> *let2) {
	vector<Kniga>::iterator a = let2->begin(); 
	int top = 0; //���������� ������ ������ 1 ��������
	int bottom = let.size() - 1; //����������, ������� ������ ������ ������ ���������� ��������
	int mid = (top + bottom) / 2; //�������� �������� ������
	for (int i = 0; ser[i] != '\0'; i++) { //������ ���� ������� ���� �� ���������
		if (ser[i] >= 65 && ser[i] <= 90) { //���� ����� �������� � ��������
			ser[i] = ser[i] + 32; //�� ���������� 32, ����� �������� ��������� �����
		}
	}
	for (vector<Kniga>::iterator j = let.begin(); j != let.end(); j++) { //���� ������� �� �������
		for (unsigned int i = 0; i < j->name.size(); i++) { //���� �� ������ �� ����� ������
			if (j->name[i] >= 65 && j->name[i] <= 90) { //���� �������� ����� � ��������
				j->name[i] = j->name[i] + 32; //�� ���������� 32 � �������� ��������� �����
			}
		}
	}
	do { //���� ��� ������ ���� ������� ���������
		if (let[mid].name == ser) { //���� �������� ����� ����, ��� ����, �� ������� �� �����
			cout << a[mid].name << "\t\t\t";
			cout << (let[mid].plus ? "+" : " ");
			cout << let[mid].num;
			break; //����� ��������, ���������� �����
		}
		else if (let[mid].name > ser){ //���� ����� � �������� ������ ��� �������, �� ���� � ������ �������� ������
			bottom = mid; //�������� ������� ����
			mid = (top + bottom) / 2; //������� ����� �������� � ������ ��������
		}
		else {
			mid++; //����� �������� �� 1
			top = mid; //������ ������ ��������� ����� ������ ������ ��������
			mid = (top + bottom) / 2; //������� ����� �������� ������ ������ ������ ��������� � ��������� ��������� � ������� �� 2
		}
		if ((bottom - top) == 0 && let[mid].name != ser) {
			cout << "������ �� �������"; //����������, ��� ������ �� �������
			break; //��������� ����
		}
	} while (true); //���� ���� �� �������� break
}

int Kniga::write2(unsigned int *c) {
	int f = 0; //���������� ��� �������� �� ������� ������ ��� ����� ������ ��������
	cout << "������� ���: "; //����� �� ����� ������� ������ ����� ��������
	cin >> name; //������� ����� �����
	*c = size(name); //����������� �������� � ����� ��� ������������ � �������
	if((f = write()) == -2) { //������������ ���������� f ��������� ���������� ������� write(), ���� -2, ������ ����� �������� ������� �������
		do{
			cout << "�� ����� ����������� ������� �����, ������� ��� �������� ������."<<endl; //����� ���������, ��� ������� �����
			cin >> name; //��������� ������ ����� �����
			*c = size(name); //����� ��������� ������ ���������� �������� � ���������� c
			f = write(); //��������� ����� ������� ������ ������ �������� � ������� ���������� � f
		} while (f == -2); //���� ������������ �� ������ ����� �������� ������ ������, ����� ����������� ������ �������� ��� ��������
	}else if (f == -1) { //���� ������� ������� �������� -1, �� ���� ������� -1, ��� ��������, ��� ������������ ���� 0 � ������ ��������
		return -1; // ������� -1
	}
	else if (f == 0) { //���� ������� ������� 0, ������ ��� ������ � ����� ���������� ���� ������� ���������
		return 0; //������� 0
	}
	return 0;
}

void Kniga::print(int *ch) {
	ofstream f; //���������� ������� ������
	f.open("NUMBERS.txt", ios::app); //�������� ���� � ���������� app ��� ������ � ����� ����� ��� �������� ���������� ����������
	cout <<"   " << name; //����� �����
	f << "  "<<name; //������ ����� � ���� � ��������
	for (unsigned int i = 0; i < *ch - size(name); i++) { //������������ �� ������ �� ���������� �������� � �����
		cout << " "; //������ �������� ��� ��������
		f << " "; //������ �������� � ����
	}
	for (int i = 0; i < 24-*ch; i++) { //������ ����� 24-*ch �������� ������� ���������
		cout << " "; //������ ��������
		f << " "; //������ �������� � ����
	}
	cout << (plus ? "+" : " ");//����� ����� + ��� ������� ���� � plus �������� 1 ��� 0
	f << (plus ? "+" : " "); //������ ����� + � ����
	cout <<num << endl; //����� ������ ��������
	f << num<<endl; //������ ������ �������� � ����
	f.close(); //�������� �����
}

int Kniga::write() {
	string a, b(50, ' '); //������ ��� ������ � ��� ������� ���������
	unsigned int c[100] = {}; //������ ��� ������ ���������� ���� � ������ ��������
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //������� ������ �����, ���� ������ ����� ������ �� ��������� ���������
	cout << "������� �����: "; //������ ����� ������
	cin>>a; //������� ��� ����� ������ ��������
	if (a[0] == '0') { //���� ������ ������ 0, �� ���������� -1 
		return -1;
	}
	else if (a[0] == '+') { //���� ������ ������ +, �� �������� ������ �������� �� ������� �������� ������� 
		if (CheckStr(&a[1], &b[0], c) == 0) { //���� ������� �������� ������ ����� 0, �� ������ ���������� ���������� �������� � ������ �� ����
			plus = 1; //������������ ���������� �������� 1 �.� ������ ��������� ��� + 
			num = atoll(&b[0]); //������� � int ������ ���������� ������� ������ ��������
			return 0; //������� 0 �.� 
		}
		else {
			return -2; //������� -2 � ������ ���� ��������� ���������� ��������
		}
	}
	else {
		if (CheckStr(&a[0], &b[0], c) == 0) { //���� ������ ������ �� +, �� �������� �������� ������ � ������� �������� � 1 ��������
			plus = 0; //������������� 0 �.� ������� ���� ���� �� ����������
			num = atoll(&b[0]); //������� ���������� � ������������ ����� � ���������� ���
			return 0; //������� 0
		}
		else {
			return -2; //������� -2 � ������ ���� ��������� ���������� ��������
		}
	}
}

int sort(vector<Kniga> &let) {
	int srav = 0; //���������� �����
	for (unsigned int i = 0; i < let.size(); i++) { //������ ������ ����� �� ��������� ���� ��� �������� ����������
		if (let[i] >= 97 && let[i] <= 122) { //���� ������ ������ ����������� ���������
			let[i] - 32; //�� �������� 32 �� �������, ������� ��������� �����
		}
	}
	for (unsigned int s = 0; s < let.size(); s++) { //������ �� ����� ���������� ������� �������
		for (unsigned int g = let.size()-1; g > 0; g--) { //�������� ���� ������ � ����� �� ������ �� ������� ��������
			srav++; //���������� 1 �.� ��������� ���������
			if (let[g] < let[g-1]) { //��������� ����, ��� ������������������ ���������� ������ ����� �������
				swap(let[g-1], let[g]); //������ ���� ��������� ������������� ������� ������� ���� � ������
			}
		}
	}
	return srav; //������� ���������� ��������� ��� ������ �� �����
}