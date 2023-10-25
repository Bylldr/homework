#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
double area_triangle(double a, double b, double c)
{

	double p = (a + b + c) / 2,s;
	if (a <= 0 || b <= 0 || c <= 0) {
		puts("��������� ������������ �� ����������");
		s = 0;
	}
	else
		s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

void name(int a)
{
	switch (a)
	{
	case 3:
		printf("�����������");
		break;
	case 4:
		printf("���������������");
		break;
	case 5:
		printf("������������");
		break;
	}
}
void draw_tritangle(int h)
{
	int left, right;
	left = right = (h-1);

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < right + 1; col++)
		{
			if (row == h-1)
			{
				printf("*");
			}
			else
			{
				if ((col >= left) && (col <= right))
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
		left--;
		right++;
	}
}
void main()
{
	 setlocale(LC_CTYPE, "RUS");
	 int chose,d,h;
	 double a, b, c;
	 char s = '.';
	 while (s != '!') 
	 {

		 puts("�������� ��������:1) ���������� �������;2) ������� ����������� ������;3) ���������� ������");
		 scanf("%d", &chose);
		 switch (chose) {
		 case 1:
			 puts("������� ������� ������������:");
			 scanf("%lf%lf%lf", &a, &b, &c);
			 printf("%lf\n", area_triangle(a, b, c));
			 break;
		 case 2:
			 puts("������� ��������d� ������:");
			 scanf("%d", &d);
			 name(d);
			 puts("\n");
			 break;
		 case 3:
			 puts("������� ������:");
			 scanf("%d", &h);
			 puts("\n");
			 draw_tritangle(h);
			 break;
		 default:
			 puts("����������� ������� �������:");
			 break;
		 }
		 getchar();
		 puts("��� ���������� ������ ��������� ������� '!'");
		 scanf("%c", &s);
	 }

	
	 
	 return 0;
}
