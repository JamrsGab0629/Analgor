#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;   // many duplicates
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quick3(int arr[], int low, int high) {
    if (low >= high) return;

    int lt = low, gt = high;
    int pivot = arr[low];
    int i = low + 1;

    while (i <= gt) {
        if (arr[i] < pivot)
            swap(&arr[i++], &arr[lt++]);
        else if (arr[i] > pivot)
            swap(&arr[i], &arr[gt--]);
        else
            i++;
    }

    quick3(arr, low, lt - 1);
    quick3(arr, gt + 1, high);
}

int main() {
    int n = 10000000;
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    random_array(arr, n);

    quick3(arr, 0, n - 1);

    free(arr);
    return 0;
}
