#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include<math.h>

void LAB5()
{
	setlocale(LC_CTYPE, "RUS");
	puts("������������ 5 �������� ������ ������� 6\n\n");
	float x = 0.01655, y = -2.75, z = 0.15,b;

	b = fabs(sqrt(10 * (pow(x, 1. / 3) + pow(x, y + 2)))*(pow(asin(z),2)-fabs(x-y)));
	printf("�������� ���������: %f ��� x = %f ,y = %f ,z = %f\n", b, x, y, z);
}
int main()
{
	setlocale(LC_CTYPE, "RUS");
	puts("������������ 6 �������� ������ ������� 6\n\n");
	
	double x, y, r;
	puts("������� x:");
	scanf("%lf,", &x);
	puts("������� y:");
	scanf("%lf,", &y);

	r = sqrt(x * x + y * y);
	if (r>1&&r<2||r>3)
	{
		puts("����� � ��������� ������������ �� ����� � ���������� ����");
	}
	else {
		puts("����� � ��������� ������������ ����� � ���������� ����\n");

	}
	LAB5();
	system("pause");



}