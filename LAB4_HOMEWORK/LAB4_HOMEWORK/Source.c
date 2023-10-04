#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
int main()
{
	float x;
	setlocale(LC_CTYPE, "RUS");
	puts("Введите расстояние,которое пробежал мальчик:");
	scanf("%f", &x);
	printf("Время за которое мальчик пробежал расстояние:%.2f\n",x/(3*4));
	getchar();
	system("pause");

}