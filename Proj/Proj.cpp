﻿#include "Fn.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, ""); //Русский язык
	char a[32], b[32];// Объявление массивов типа char для заполнения 
	unsigned int ch[101] = { }, i = 0, sel, check, go = 0, count2[101]{}; // Объявление переменных
	printf("1 - Приветствие\n2 - Перевод десятичного числа в двоичное\nВыберите функцию: ");
	scanf_s("%d", &sel); //Ввод выбора функции
	if ( sel == 1 ) {
		printf("\nПривет");
	}

	if ( sel == 2 ) {
		printf("Введите неотрицательное десятичное число для перевода: \n"); // Вывод текста
		do { //Начало цикла
			scanf_s("%s", a, 32); //Ввод числа для перевода в двоичный код
			check = CheckStr(a, b, &ch[i]); //Присваивание переменной check значение возврата функции CheckStr

			if ( check != -1 ) { // Проверка на наличие ошибок
				if ( ch[i] == 10 ) {
					int hh = checkLen(b);
					if ( hh == 0 ) {
						go = atoll(b); //char переводим в int
						cleanArr(b); //Очистка массива
						count2[i] = go; //Присваиваем элементу массива наше число, что было переведено в int в строке 24
						i++; //Счетчик для перехода по массиву count2 и для подсчета количества введенных чисел всего
					}
					else {
						printf("Число больше чем 4294967295\n");
						ch[i] = 0;
						cleanArr(b);
					}
				}
				else {
					go = atoll(b); //char переводим в int
					cleanArr(b); //Очистка массива
					count2[i] = go; //Присваиваем элементу массива наше число, что было переведено в int в строке 24
					i++; //Счетчик для перехода по массиву count2 и для подсчета количества введенных чисел всего
				}
				}
			else {
			printf("Цифр больше 10, введите еще раз\n");
			cleanArr(b); //Очистка массива
			}
		} while ( a[0] != '0' && i <= 100 ); //Цикл будет действовать пока мы не введем 0
		Table(&i, count2, ch); //Функция выводы таблицы на экран с передаей 2 переменных
	}
	if ( sel == 3 ) {
//		int c = 10;
		char ci[] = "4294967296";
		//char ci[] = "54875";
		checkLen(ci);
//		printf("%d", c);
		/*		printf("Test on dynamic memory");
				int n;
				scanf_s("%d", &n);
				int* check = nullptr;
				check = (int*)malloc(n * sizeof(int));
				if ( check == NULL ) {
					printf("Ошибка, память не выделена");
				}
				else {

					for ( int i = 0; i < n; i++ ) {
						scanf_s("%d", &check[i]);
					}
					for ( int i = 0; i < n; i++ ) {
						printf("%d", check[i]);
					}
					free(check);
				}
			}
			return 0; // Возврат 0 в случае успешного закрытия программы*/
	}
}