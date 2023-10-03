#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
int main()
{
	float x;
	setlocale(LC_CTYPE, "RUS");
	puts("Введите расстояние,которое пробежал мальчик:");
	scanf("%f", &x);
	printf("Время за которое мальчик пробежал расстояние:%.2f", 4 * 3 * x);
	getchar();
	system("pause");

}