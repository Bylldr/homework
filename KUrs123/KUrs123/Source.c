#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROWS 7
#define COLUMNS 7

char gameBoard[ROWS][COLUMNS] = {
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},

};
char answers[ROWS][COLUMNS] = {
       'B','C','E','_','D','_','A',
       '_','D','C','A','_','E','B',
       'C','_','A','B','_','D','E',
       '_','A','B','D','E','C','_',
       'A','B','D','E','C','_','_',
       'E','_','_','C','B','A','D',
       'D','E','_','_','A','B','C',
   };
void printrules();
void createGameBoard();
void printGameBoard();
int game(int a);
void checkRecord(int new_record);
int main()
{
    int Complexity;
    int choose;
    char finish = '+';
    FILE* fp;
    fp = fopen("game_record.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    fclose(fp);
    return 0;
}
  
    setlocale(LC_CTYPE, "RUS");
    while (finish != '!')
    {
        puts("������������ � ���� ������ ���������, ����������� �������� ��������:\n1)������������ � ��������� ����\n2)���������� � ����\n3)��������� ����");
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            printrules();
            break;
        case 2:
        {
            createGameBoard();
            puts("������ ������� ��������� ����:\n1)������,����������� ��������� 5 ���\n2)�������,����������� ��������� 3 ���\n3)�������,����������� ��������� 1 ���\n");
            scanf_s("%d", &Complexity);
            game(Complexity);
            break;
        }
        case 3:
        {
            finish = '!';
        }
        }
    }
    puts("���� ��� �����!");
    return 0;

}



void createGameBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            gameBoard[i][j] = '_';
        }

    }
}
void printGameBoard()
{
    char str1[7] = { 'B','D', 'C', 'A', 'A',' ','D' };//������� ���� ����� �� �����
    char str2[7] = { 'A','B', 'E', 'C', ' ','D',' ' };//������� ���� ������ �� �����
    printf("        B     E  A  D  E  A\n");
    printf("        0  1  2  3  4  5  6 \n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("   %d  %c",i, str1[i]);
        for (int j = 0; j < ROWS; j++)
        {
            printf("|%c|", gameBoard[i][j]);
            if (j == 6)
                printf("%c",  str2[i]);
        }
        puts("\n");

    }
    printf("          D  E  D  C  A     C\n");
}
int game(int a)
{

    int x, y, TRY, repeat, save = 0;
    char temp;
    bool Equa = true;

    switch (a)
    {
    case 1:
        TRY = 5;
        printf("�� ������ ������ ��������� � ���: %d �������, ����� ����� ;)\n", TRY);
        while (TRY > 0)
        {
            printf("%d �������� �������");
            printGameBoard();
            puts("������� ����� ������: ");
            scanf_s("%d", &x);
            puts("������� ����� �������: ");
            scanf_s("%d", &y);
            puts("������� �������: ");
            getchar();
            scanf_s("%c", &temp);
            if (temp == answers[x][y])
            {
                gameBoard[x][y] = temp;
                printGameBoard();
                save += 1;
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLUMNS; j++)
                    {
                        if (gameBoard[i][j] != answers[i][j])
                        {
                            Equa = false;
                            
                        }
                        else
                            Equa = true;

                    }
                }
                if (Equa == true)
                {
                    printf("����������� �� �������� ��� ������������ : %d\n", save);
                    checkRecord(save);
                    return 0;
                }
            }

                

            else
            {
                puts("��������� ���");
                TRY--;
                printf("� ��� �������� : %d �������", TRY);
            }
        }
        printf("� ��������� �� ���������,��� ���������:%d\n", save);

        puts("\n");
        checkRecord(save);
        break;
    case 2:
        TRY = 3;
        printf("�� ������ ������ ��������� � ���: %d �������, ����� ����� ;)\n", TRY);
        while (TRY > 0)
        {
            printGameBoard();
            puts("������� ����� ������: ");
            scanf_s("%d", &x);
            puts("������� ����� �������: ");
            scanf_s("%d", &y);
            puts("������� �������: ");
            getchar();
            scanf_s("%c", &temp);
            if (temp == answers[x][y])
            {
                gameBoard[x][y] = temp;
                printGameBoard();
                save += 1;
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLUMNS; j++)
                    {
                        if (gameBoard[i][j] != answers[i][j])
                        {
                            Equa = false;

                        }
                        else
                            Equa = true;

                    }
                }
                if (Equa == true)
                {
                    printf("����������� �� �������� ��� ������������ : %d\n", save);
                    checkRecord(save);
                    return 0;
                }
            }
            else
            {
                puts("��������� ���");
                TRY--;
                printf("� ��� �������� : %d �������", TRY);
            }
        }
        printf("� ��������� �� ���������,��� ���������:%d\n", save);
        puts("\n");
        checkRecord(save);
        break;
    case 3:
        TRY = 1;
        printf("�� ������ ������ ��������� � ���: %d �������, ����� ����� ;)\n", TRY);
        while (TRY > 0)
        {

            printGameBoard();
            puts("������� ����� ������: ");
            scanf_s("%d", &x);
            puts("������� ����� �������: ");
            scanf_s("%d", &y);
            puts("������� �������: ");
            getchar();
            scanf_s("%c", &temp);
            if (temp == answers[x][y])
            {
                gameBoard[x][y] = temp;
                printGameBoard();
                save += 1;
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLUMNS; j++)
                    {
                        if (gameBoard[i][j] != answers[i][j])
                        {
                            Equa = false;

                        }
                        else
                            Equa = true;

                    }
                }
                if (Equa == true)
                {
                    printf("����������� �� �������� ��� ������������ : %d\n", save);
                    checkRecord(save);
                    return 0;
                }
            }
            else
            {
                puts("��������� ���");
                TRY--;
            }


        }
        printf("� ��������� �� ���������,��� ���������:%d\n", save);

        puts("\n");
        checkRecord(save);
        break;

        }

        return save;
  }

void printrules()
{
    puts("\t\t\t\t||�������||\n���������� ��������� ����������� �������, ������ ��������� ���������:\n1)� ������ ���� � ������� ����� ������ ����������� ���� ��������\n2)��������� ������ ����� ���� �������\n3)�����,������� �� ������� �����,����������,����� ����� ������ ���������� ������\n");

}
void checkRecord(int new_record) {
    FILE* fp;
    int record;
    fp = fopen("game_record.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fp, "%d", &record);
    if (new_record > record) {
        fprintf(fp, "%d", new_record);
        printf("����������� �� ������ ������: %d\n\n", new_record);
    }
    else {
        printf("������ ��������� : %d\n\n", record);
    }
    fclose(fp);
}


