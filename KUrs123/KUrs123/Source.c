#include <stdio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define ROWS 7
#define COLUMNS 7

char gameBoard[ROWS][COLUMNS];
char answers[ROWS][COLUMNS] = {
    {'B','C','E','_','D','_','A'},
    {'_','D','C','A','_','E','B'},
    {'C','_','A','B','_','D','E'},
    {'_','A','B','D','E','C','_'},
    {'A','B','D','E','C','_','_'},
    {'E','_','_','C','B','A','D'},
    {'D','E','_','_','A','B','C'},

};
int main()
{
    int Complexity;
    int choose;
    char finish = '+';
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

void printrules();
void createGameBoard();
void printGameBoard();
int game(int a);
void saveRecord(int record);
void displayRecord();
void updateRecord(int newRecord);


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
    printf("          B     E  A  D  E  A\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("\t%c", str1[i]);
        for (int j = 0; j < ROWS; j++)
        {
            printf("|%c|", gameBoard[i][j]);
            if (j == 6)
                printf(" %c", str2[i]);
        }
        puts("\n");

    }
    printf("          D  E  D  C  A     C\n");
}
int game(int a)
{

    int x, y, TRY, repeat, save = 0;
    char temp;

    switch (a)
    {
    case 1:
        TRY = 5;
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

            }
            else
            {
                puts("�������� ���");
                TRY--;
                printf("�������� �������: %d\n\n", TRY);


            }

        }
        printf("� ��������� �� ���������,��� ���������:%d\n", save);
        updateRecord(save);
        puts("\n");
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

            }
            else
            {
                puts("�������� ���");
                TRY--;
                printf("�������� �������: %d\n\n", TRY);
            }
        }
        printf("� ��������� �� ���������,��� ���������:%d\n", save);
        updateRecord(save);
        puts("\n");
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

            }
            else
            {
                puts("�������� ���");
                TRY--;
                printf("�������� �������: %d\n\n", TRY);
            }

        }
        printf("� ��������� �� ���������,��� ���������:%d\n", save);
        updateRecord(save);
        puts("\n");
        break;


    }

    return save;
}
void printrules()
{
    puts("\t\t\t\t||�������||\n���������� ��������� ����������� �������, ������ ��������� ���������:\n1)� ������ ���� � ������� ����� ������ ����������� ���� ��������\n2)��������� ������ ����� ���� �������\n3)�����,������� �� ������� �����,����������,����� ����� ������ ���������� ������\n");

}
void saveRecord(int record) {
    FILE* fp;
    fp = fopen("game_record.txt", "w");
    fprintf(fp, "%d", record);
    fclose(fp);
}
void displayRecord() {
    FILE* fp;
    int record;
    fp = fopen("game_record.txt", "r");
    fscanf(fp, "%d", &record);
    printf("������ ���������: %d\n", record);
    fclose(fp);
}
void updateRecord(int newRecord) {
    FILE* fp;
    int currentRecord;
    fp = fopen("game_record.txt", "r");
    fscanf(fp, "%d", &currentRecord);
    fclose(fp);
    if (newRecord > currentRecord) {
        saveRecord(newRecord);
        printf("����������� �� ������ ������: %d\n", newRecord);
    }
    else {
        printf("������ ���������: %d\n", currentRecord);
    }
}




int main()
{
    int Complexity;
    int choose;
    char finish = '+';
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
