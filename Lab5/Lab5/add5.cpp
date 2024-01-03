#include "../../Proj/Fn.h"
#include <iostream>

int Kniga::write2(unsigned int *c) {
	int f = 0;
	cout << "Введите имя: ";
	cin >> name;
	*c = size(name);
	if((f = write()) == -2) {
		do{
			cout << "Вы ввели недопустимо длинный номер, введите имя абонента заново."<<endl;
			cin >> name;
			*c = size(name);
			f = write();
		} while (f == -2);
	}else if (f == -1) {
		return -1;
	}
	else if (f == 0) {
		return 0;
	}
	return 0;
}

void Kniga::print(unsigned int *ch) {
	cout << name << " ";
	for (unsigned int i = 0; i < (21 - *ch); i++) { 
		cout << "."; //Печать точки для удобства
	}
	cout << (plus ? "+" : " ");
	cout << num << endl;
}

int Kniga::write() {
	char a[40] = {}, b[40] = {};
	unsigned int c[100] = {};
	Nomer nam;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Очистка буфера ввода
	cout << "Введите номер: ";
	cin.getline(a, 40);
	if (a[0] == '0') {
		return -1;
	}
	else if (a[0] == '+') {
		if (CheckStr(&a[1], b, c) == 0) {
			plus = 1;
			num = atoll(b);
			return 0;
		}
		else {
			return -2;
		}
	}
	else {
		if (CheckStr(a, b, c) == 0) {
			plus = 0;
			num = atoll(b);
			return 0;
		}
		else {
			return -2;
		}
	}
	return 0;
}