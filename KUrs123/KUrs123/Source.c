#define ROW  7
#define COLS 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void field();// функция создания игровго поля

int main ()
{
	setlocale(LC_CTYPE, "RUS");
	field();
	return 0;
}

void field()
{
	char str1[7] = { 'B','D', 'C', 'A', 'A',' ','D' };//Колонка букв слева от сетки
	char str2[7] = { 'A','B', 'E', 'C', ' ','D',' ' };//Колонка букв справа от сетки
	char field[ROW][COLS];//Игровой массив
	char finish = ' ',temp =' ';
	int x, y;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			field[i][j] = '_';

		}
	}
	while (finish != '!')
	{
		puts("Введите номер строки: ");
		scanf("%d", &x);
		puts("Введите номер столбца: ");
		scanf("%d", &y);
		puts("Введите значние: ");
		getchar();
		scanf("%c", &temp);
		field[x][y] = temp;
		for (int i = 0; i < ROW; i++)
		{
			printf("\t%c", str1[i]);
			for (int j = 0; j < COLS; j++)
			{
				printf("|%c|", field[i][j]);
				if (j == 6)
					printf(" %c", str2[i]);
			}
			puts("\n");

		}
		getchar();
		puts("Для завершения работы программы введите '!'");
		scanf("%c", &finish);
	}
}