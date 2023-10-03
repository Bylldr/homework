#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_CTYPE, "RUS");
	float price, road;
	puts("Введите расстояние:");
	scanf("%f", &road);
	puts("Введите стоимость бензина:");
	scanf("%f", &price);
	printf("Стоимость поездки:%.2f", price * road);
	getchar();
	

}
