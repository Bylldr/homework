#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define N 50
// ��������� "���������"
struct Employee {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char position[50];
    float salary;
    char birthDate[11];
};

// ������� ��� ������ ���������� � �����������, ���������� � ���
void printEmployeesBornInMay(struct Employee employees[], int n) {
    printf("����������, ���������� � ���:\n");
    for (int i = 0; i < n; i++) {
        if (strncmp(employees[i].birthDate+3, "05", 2) == 0) {
            printf("�������: %s\n", employees[i].lastName);
            printf("���: %s\n", employees[i].firstName);
            printf("��������: %s\n", employees[i].middleName);
            printf("���������: %s\n", employees[i].position);
            printf("��������: %.2f\n", employees[i].salary);
            printf("���� ��������: %s\n", employees[i].birthDate);
            printf("\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    // ���������� �����������
    int n;

    printf("������� ���������� �����������: ");
    scanf("%d", &n);

    // �������� ������� �������� "���������"
    struct Employee employees[N]; // ������ �������� if(n < N), �� ��� ��������, ����� ������


    // ���������� ����� ��������
    for (int i = 0; i < n; i++) {
        printf("������� ������ ��� ���������� %d:\n", i + 1);
        printf("�������: ");
        scanf("%s", employees[i].lastName);
        printf("���: ");
        scanf("%s", employees[i].firstName);
        printf("��������: ");
        scanf("%s", employees[i].middleName);
        printf("���������: ");
        scanf("%s", employees[i].position);
        printf("��������: ");
        scanf("%f", &employees[i].salary);
        printf("���� �������� (� ������� dd.mm.yyyy): ");
        scanf("%s", employees[i].birthDate);
    }

    // ����� ���������� � �����������, ���������� � ���
    printEmployeesBornInMay(employees, n);

    return 0;
}