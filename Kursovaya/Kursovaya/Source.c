#include <stdio.h>
//Варинт 6 задачи D
int main()
{
	int ROW = 7, COLS = 7;
	char c = '_';
	char str1[7] = { 'B','D', 'C', 'A', 'A',' ','D'};
	char str2[7] = { 'A','B', 'E', 'C', ' ','D',' ' };
	puts("\t  B     E  A  D  E  A ");
	for (int i = 0; i < ROW; i++)
	{
		printf("\t%c", str1[i]);
		for (int j = 0; j < COLS; j++)
		{
			printf("|%c|", c);
			
			if (j == 6)
				printf(" %c", str2[i]);
		}
		puts("\n");
	}
	puts("\t  D  E  D  C  A     C ");

	return 0;

}