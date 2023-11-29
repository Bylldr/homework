#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define N 50
// Структура "Сотрудник"
struct Employee {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char position[50];
    float salary;
    char birthDate[11];
};

// Функция для вывода информации о сотрудниках, родившихся в мае
void printEmployeesBornInMay(struct Employee employees[], int n) {
    printf("Сотрудники, родившиеся в мае:\n");
    for (int i = 0; i < n; i++) {
        if (strncmp(employees[i].birthDate+3, "05", 2) == 0) {
            printf("Фамилия: %s\n", employees[i].lastName);
            printf("Имя: %s\n", employees[i].firstName);
            printf("Отчество: %s\n", employees[i].middleName);
            printf("Должность: %s\n", employees[i].position);
            printf("Зарплата: %.2f\n", employees[i].salary);
            printf("Дата рождения: %s\n", employees[i].birthDate);
            printf("\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    // Количество сотрудников
    int n;

    printf("Введите количество сотрудников: ");
    scanf("%d", &n);

    // Создание массива структур "Сотрудник"
    struct Employee employees[N]; // сделай проверку if(n < N), то код работает, иначе ошибка


    // Заполнение полей структур
    for (int i = 0; i < n; i++) {
        printf("Введите данные для сотрудника %d:\n", i + 1);
        printf("Фамилия: ");
        scanf("%s", employees[i].lastName);
        printf("Имя: ");
        scanf("%s", employees[i].firstName);
        printf("Отчество: ");
        scanf("%s", employees[i].middleName);
        printf("Должность: ");
        scanf("%s", employees[i].position);
        printf("Зарплата: ");
        scanf("%f", &employees[i].salary);
        printf("Дата рождения (в формате dd.mm.yyyy): ");
        scanf("%s", employees[i].birthDate);
    }

    // Вывод информации о сотрудниках, родившихся в мае
    printEmployeesBornInMay(employees, n);

    return 0;
}