#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_CTYPE, "RUS");
	float price, road;
	puts("������� ����������:");
	scanf("%f", &road);
	puts("������� ��������� �������:");
	scanf("%f", &price);
	printf("��������� �������:%.2f", price * road);
	getchar();
	

}
