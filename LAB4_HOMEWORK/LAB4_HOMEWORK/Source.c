#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
int main()
{
	float x;
	setlocale(LC_CTYPE, "RUS");
	puts("������� ����������,������� �������� �������:");
	scanf("%f", &x);
	printf("����� �� ������� ������� �������� ����������:%.2f", 4 * 3 * x);
	getchar();
	system("pause");

}