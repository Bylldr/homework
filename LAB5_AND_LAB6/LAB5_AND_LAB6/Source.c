#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include<math.h>

void LAB5()
{
	setlocale(LC_CTYPE, "RUS");
	puts("Лабораторная 5 домашняя работа вариант 6\n\n");
	float x = 0.01655, y = -2.75, z = 0.15,b;

	b = fabs(sqrt(10 * (pow(x, 1. / 3) + pow(x, y + 2)))*(pow(asin(z),2)-fabs(x-y)));
	printf("Итоговый результат: %f при x = %f ,y = %f ,z = %f\n", b, x, y, z);
}
int main()
{
	setlocale(LC_CTYPE, "RUS");
	puts("Лабораторная 6 домашняя работа вариант 6\n\n");
	
	double x, y, r;
	puts("Введите x:");
	scanf("%lf,", &x);
	puts("Введите y:");
	scanf("%lf,", &y);

	r = sqrt(x * x + y * y);
	if (r>1&&r<2||r>3)
	{
		puts("Точка с заданными координатами не лежит в закрашеной зоне");
	}
	else {
		puts("Точка с заданными координатами лежит в закрашеной зоне\n");

	}
	LAB5();
	system("pause");



}