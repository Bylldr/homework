#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int zarplata(int a);

int main()
{
	int a=0;
	char finish = '+';
	setlocale(LC_CTYPE, "RUS");
	while (finish != '!')
	{
		puts("Введите номер сотрудника:");
		scanf("%d", &a);
		zarplata(a);
		printf("Годовая зарплата равна сотрудника № %d: %d\n", a, zarplata(a));
		puts("Для заверешния введите !\n");
		getchar();
		scanf("%c", &finish);
	}
	return 0;
}
int zarplata(int a)
{

	int i, j, sum = 0;
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
			printf("| %5d | ",arr[i][j]);

		}
		puts("\n");
	}
	
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (i == a)
				sum += arr[i][j];

		}

	}
	return  sum;
}