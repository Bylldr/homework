#define ROW  7
#define COLS 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void field(int TRY);// ������� �������� ������� ����

int main ()
{
	int TRY;
	setlocale(LC_CTYPE, "RUS");
	field(3);
	return 0;
}


void field()
{
	int TRY = 3;
	char str1[7] = { 'B','D', 'C', 'A', 'A',' ','D' };//������� ���� ����� �� �����
	char str2[7] = { 'A','B', 'E', 'C', ' ','D',' ' };//������� ���� ������ �� �����
	char field[ROW][COLS];//������� ������
	char answers[ROW][COLS] = {
	{'B','C','E','_','D','_','A'},
	{'_','D','C','A','_','E','B'},
	{'C','_','A','B','_','D','E'},
	{'_','A','B','D','E','C','_'},
	{'A','B','D','E','C','_','_'},
	{'E','_','_','C','B','A','D'},
	{'D','E','_','_','A','B','C'},

	};
	char finish = ' ', temp = ' ';
	int x, y;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			field[i][j] = '_';

		}
	}


	while (TRY != 0||answers!=field)
	{
		puts("������� ����� ������: ");
		scanf("%d", &x);
		puts("������� ����� �������: ");
		scanf("%d", &y);
		puts("������� �������: ");
		getchar();
		scanf("%c", &temp);
		if (temp == answers[x][y])
		{
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

		}
		else
		{
			puts("�������� ���");
			TRY--;
			printf("�������� �������: %d\n", TRY);
		}
	}
}