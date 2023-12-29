#include "/Users/andre/source/repos/CHuvaCK21/Proj/Proj/Fn.h"
#include <iostream>
#include <string>
#include <locale>
#include <vector>

int main() {
	setlocale(LC_ALL, "RU");
	int i = 0, g;
	unsigned int ch[100] = {};
	cout << "Привет, ты попал в записную книжку, начнем. " << endl;
	vector <Kniga> let;
	Kniga tel;
	do {
		if((g = tel.write2(&ch[i])) == 0) {
			let.push_back(tel);
			i++;
		}
		else if(g == -1){
			break;
		}
	} while (i < 100);

/*	for (auto i = let.begin(); i != let.end(); i++) {
		i->print();
	}*/
/*	for (int g = 0; g < i; g++) {
		tel[g].print();
}*/
	Tabl(let, i, ch);
return 0;
}