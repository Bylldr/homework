#include <stdio.h>
#define N 5

// ������� ��� ���������� ��������� �� ���� �����
int maxOfThree(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    else if (b >= a && b >= c) {
        return b;
    }
    else {
        return c;
    }
}

// ������� ��� �������� ������� d0, d1, ..., dn
void createArray(int* a, int* b, int* c, int* d, int n) {
    for (int i = 0; i <= n; ++i) {
        d[i] = maxOfThree(a[i % n], b[i % n], c[i % n]);
    }
}

// ������� ��� ����������� ��������� �������
void displayArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int d[N + 1];
    int n = 5;

    // �������������� ��� �������� ������� a, b, c
    int a[] = { 1, 4, 7, 2, 5 };
    int b[] = { 3, 6, 9, 1, 4 };
    int c[] = { 5, 8, 2, 7, 3 };

    // ������� ������ d

    createArray(a, b, c, d, n);

    // ���������� ���������
    displayArray(d, n + 1);

    return 0;
}