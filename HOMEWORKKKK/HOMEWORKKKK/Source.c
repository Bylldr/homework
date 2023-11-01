#define _CRT_SECURE_NO_WARNINGS
#define size 10
#include <stdio.h>
#include <locale.h>

int main() {
    int arr[size]; 
    int num1 = -1; 
    int num2 = -1; 
    float count=0, sum=0;
    float temp;
    for (int i = 0; i < 10; i++)

    {

        printf("a[%d] = ", i + 1);

        scanf("%f", &temp);

        arr[i] = temp;

    }
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (arr[i] < 0) {
            if (num1 == -1) {
                num1 = i;
            }
            else {
                num2 = i;
                break;
            }
        }
    }
    for (int i = num1 + 1; i <num2; i++) {
        sum += arr[i];
        count++;
    }
    printf("%.2f", sum/count);

    
 

    return 0;
}