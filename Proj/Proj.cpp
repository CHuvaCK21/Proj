#include "Fn.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include < string.h >

int main()
{
	setlocale(LC_ALL, ""); //Русский язык
	char a[32], b[32];// Объявление массивов типа char для заполнения 
	unsigned int i = 0, sel, check, go = 0, count2[100]; // Объявление переменных
	printf("1 - Приветствие\n2 - Перевод десятичного числа в двоичное\nВыберите функцию: ");
	scanf_s("%d", &sel); //Ввод выбора функции
	if ( sel == 1 ) {
		printf("\nПривет"); 
	}

	if ( sel == 2 ) {
		printf("Введите число для перевода: \n"); // Вывод текста
		do { //Начало цикла
			scanf_s("%s", a, 32); //Ввод числа для перевода в двоичный код
			check = CheckStr(a, b); //Присваивание переменной check значение возврата функции CheckStr
			if ( check != -1){ // Проверка на то присутстсвовали ли ошибки
				go = atoll(b); //char переводим в int
				cleanArr(b); //Очистка массива
				count2[i] = go; //Присваиваем элементу массива наше число, что было переведено в int в строке 24
				i++; //Счетчик для перехода по массиму count2 и для подсчета количества введенных чисел всего
				//TrToBin(go); //Переход в функцию
			}
			else {
				printf("Цифр больше 10, введите еще раз");
				printf("\n"); //Переход на новую строку
				cleanArr(b); //Очистка массива
			}
		} while ( a[0] != '0' && i < 100); //Цикл будет действовать пока мы не введем 0
		Table(&i, count2); //Функция выводы таблицы на экран с передаей 3 переменных
	}
	if ( sel == 3 ) {
		printf("Test on dynamic memory");
		int n;
		scanf_s("%d", &n);
		int* check;
		check = (int*)malloc(n * sizeof(int));
		for ( int i = 0; i < n; i++ ) {
			scanf_s("%d", &check[i]);
		}
		for ( int i = 0; i < n; i++ ) {
		printf("%d", check[i]);
		}
		free(check);
	}

	return 0; // Возврат 0 в случае успешного закрытия программы
}