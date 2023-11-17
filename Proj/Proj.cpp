#include "Fn.h" // Подключение файла заголовка с определением функции TrToBin
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, ""); //Русский язык
	char a[32], b[32];// Объявление массивов типа char для заполнения 
	unsigned int sel, check, go = 0; // Объявление переменных
	printf("1 - Приветствие\n2 - Перевод десятичного числа в двоичное\nВыберите функцию: ");
	scanf_s("%d", &sel); //Ввод выбора функции
	if ( sel == 1 ) {
		printf("\nПривет"); 
	}

	if ( sel == 2 ) {
		printf("Введите число для перевода: "); // Вывод текста
		do { //Начало цикла
			scanf_s("%s", a, 32); //Ввод числа для перевода в двоичный код
			check = CheckStr(a, b); //Присваивание переменной check значение возврата функции CheckStr
			if ( check != -1){ // Проверка на то присутстсвовали ли ошибки
				go = atoll(b); //char переводим в int
				cleanArr(b); //Очистка массива
				TrToBin(go); //Переход в функцию
			}
			else {
				printf("Цифр больше 10");
			}
			printf("\n");
		} while ( a[0] != '0' ); //Цикл будет действовать пока мы не введем 0
	}
	if ( sel == 3 ) {
		printf("Test on dynamic memory");
		int n;
		scanf_s("%d", &n);
		int* check;
		check = (int*)malloc(n * sizeof(int));
		for ( int i = 0; i < n; i++ ) {
			scanf_s("%d", &check[i]);
			//check++;
		}
		for ( int i = 0; i < n; i++ ) {
		printf("%d", check[i]);
		//check++;
}
		free(check);
	}
	return 0; // Возврат 0 в случае успешного закрытия программы
}