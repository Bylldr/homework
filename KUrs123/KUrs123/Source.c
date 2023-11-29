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
    char str1[7] = { 'B','D', 'C', 'A', 'A',' ','D' };//Колонка букв слева от сетки
    char str2[7] = { 'A','B', 'E', 'C', ' ','D',' ' };//Колонка букв справа от сетки
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

            }
            else
            {
                puts("Неверный ход");
                TRY--;
                printf("Осталось попыток: %d\n\n", TRY);


            }

        }
        printf("К сожалению вы проиграли,ваш результат:%d\n", save);
        updateRecord(save);
        puts("\n");
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

            }
            else
            {
                puts("Неверный ход");
                TRY--;
                printf("Осталось попыток: %d\n\n", TRY);
            }
        }
        printf("К сожалению вы проиграли,ваш результат:%d\n", save);
        updateRecord(save);
        puts("\n");
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

            }
            else
            {
                puts("Неверный ход");
                TRY--;
                printf("Осталось попыток: %d\n\n", TRY);
            }

        }
        printf("К сожалению вы проиграли,ваш результат:%d\n", save);
        updateRecord(save);
        puts("\n");
        break;


    }

    return save;
}
void printrules()
{
    puts("\t\t\t\t||ПРАВИЛА||\nНеобходимо заполнить головоломку буквами, следуя следующим принципам:\n1)В каждом ряду и колонке буква должна встречаться лишь единажды\n2)Некоторые клетки могут быть постыми\n3)Буквы,стоящие на границе сетки,показывают,какая буква должна встретится первой\n");

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
    printf("Лучший результат: %d\n", record);
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
        printf("Поздравляем вы побили рекорд: %d\n", newRecord);
    }
    else {
        printf("Лучший результат: %d\n", currentRecord);
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
