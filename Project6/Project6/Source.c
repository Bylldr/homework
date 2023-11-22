#include <stdio.h>
#include <locale.h>

int find_min_index(double* ptr_array, int n, int k) {
    int min_index = -1;
    double min_value = 0;
    for (int i = 0; i < n; i++) {
        if (i % k == 0 && (min_index == -1 || ptr_array[i] < min_value)) {
            min_index = i;
            min_value = ptr_array[i];
        }
    }
    return min_index;
}


int main() {
    setlocale(LC_CTYPE, "RUS");
    double arr[] = {5,6,4,3,6};
    int n = 5;
    int k = 2;
    int min_index = find_min_index(arr, n, k);
    if (min_index != -1) {
        printf("ћинимальное значение, кратное %d, находитс€ в индексе %d\n", k, min_index);
    }
    else {
        printf("Ќе найдено минимального значени€, кратного %d\n", k);
    }
    return 0;
}