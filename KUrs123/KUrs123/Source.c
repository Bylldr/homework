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
        puts("Приветствуем в игре ПЕРВЫЕ ВСТРЕЧНЫЕ, пожалуйства выберите действие:\n1)Ознакомиться с правилами игры\n2)Приступить к игре\n3)Закончить игру");
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            printrules();
            break;
        case 2:
        {
            createGameBoard();
            puts("Вырите уровень сложности игры:\n1)Легкий,возможность ошибиться 5 раз\n2)Средний,возможность ошибиться 3 раз\n3)Тяжелый,возможность ошибиться 1 раз\n");
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
    puts("Ждем вас снова!");
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
    char str1[7] = { 'B','D', 'C', 'A', 'A',' ','D' };//Колонка букв слева от сетки
    char str2[7] = { 'A','B', 'E', 'C', ' ','D',' ' };//Колонка букв справа от сетки
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
        printf("На данном уровне сложности у вас: %d попыток, жалем удачи ;)\n", TRY);
        while (TRY > 0)
        {
            printf("%d Осталось попыток");
            printGameBoard();
            puts("Введите номер строки: ");
            scanf_s("%d", &x);
            puts("Введите номер столбца: ");
            scanf_s("%d", &y);
            puts("Введите значние: ");
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
                    printf("Поздравляем вы выиграли вам понадобилось : %d\n", save);
                    checkRecord(save);
                    return 0;
                }
            }

                

            else
            {
                puts("Невереный ход");
                TRY--;
                printf("У вас осталось : %d попыток", TRY);
            }
        }
        printf("К сожалению вы проиграли,ваш результат:%d\n", save);

        puts("\n");
        checkRecord(save);
        break;
    case 2:
        TRY = 3;
        printf("На данном уровне сложности у вас: %d попыток, жалем удачи ;)\n", TRY);
        while (TRY > 0)
        {
            printGameBoard();
            puts("Введите номер строки: ");
            scanf_s("%d", &x);
            puts("Введите номер столбца: ");
            scanf_s("%d", &y);
            puts("Введите значние: ");
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
                    printf("Поздравляем вы выиграли вам понадобилось : %d\n", save);
                    checkRecord(save);
                    return 0;
                }
            }
            else
            {
                puts("Невереный ход");
                TRY--;
                printf("У вас осталось : %d попыток", TRY);
            }
        }
        printf("К сожалению вы проиграли,ваш результат:%d\n", save);
        puts("\n");
        checkRecord(save);
        break;
    case 3:
        TRY = 1;
        printf("На данном уровне сложности у вас: %d попыток, жалем удачи ;)\n", TRY);
        while (TRY > 0)
        {

            printGameBoard();
            puts("Введите номер строки: ");
            scanf_s("%d", &x);
            puts("Введите номер столбца: ");
            scanf_s("%d", &y);
            puts("Введите значние: ");
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
                    printf("Поздравляем вы выиграли вам понадобилось : %d\n", save);
                    checkRecord(save);
                    return 0;
                }
            }
            else
            {
                puts("Невереный ход");
                TRY--;
            }


        }
        printf("К сожалению вы проиграли,ваш результат:%d\n", save);

        puts("\n");
        checkRecord(save);
        break;

        }

        return save;
  }

void printrules()
{
    puts("\t\t\t\t||ПРАВИЛА||\nНеобходимо заполнить головоломку буквами, следуя следующим принципам:\n1)В каждом ряду и колонке буква должна встречаться лишь единажды\n2)Некоторые клетки могут быть постыми\n3)Буквы,стоящие на границе сетки,показывают,какая буква должна встретится первой\n");

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
        printf("Поздравляем вы побили рекорд: %d\n\n", new_record);
    }
    else {
        printf("Лучший результат : %d\n\n", record);
    }
    fclose(fp);
}


