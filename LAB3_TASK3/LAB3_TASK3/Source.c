#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
int main()
{
    setlocale(LC_CTYPE, "RUS");
    int a;
    int b;
    printf("������� ������ �����: ");
    scanf("%d", &a);
    printf("������� ������ �����: ");
    scanf("%d", &b);
    printf("_______________________________\n|%9s|%9s|%9s|\n_______________________________\n|%4d*%4d|%4d+%4d|%4d-%4d|\n________________________________\n|%9d|%9d|%9d|\n________________________________", "a*b", "a+b", "a-b", a, b, a, b, a, b, a * b, a + b, a - b);
    system("pause");
    

}