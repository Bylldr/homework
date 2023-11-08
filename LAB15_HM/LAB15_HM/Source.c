#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int zarplata(int a)
{
	int i, j,sum=0;
	int arr[20][12];
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 12; j++)
		{
			arr[i][j] = 350;
			if (i != 0 && j != 0)
			{
				arr[i][j] += arr[i - 1][j - 1];
			}
			printf("%5d ",arr[i][j]);

		}
		puts("\n");
	}
	for (i=0;i<20;i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (i==a)
				sum += arr[i][j];

		}

	}
	return  sum;
}
int main()
{
	int a=0;
	setlocale(LC_CTYPE, "RUS");
	puts("Введите номер сотрудника:\n\n");
	scanf("%d", &a);
	zarplata(a);
	printf("Годовая зарплата равна сотрудника № %d: %d", a, zarplata(a));
	return 0;
}