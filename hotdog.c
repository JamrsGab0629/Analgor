#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        int swapped = 0;
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0) break;
    }
}

int main(){
    int n = 100;   
    int *arr = malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    random_array(arr, n);

    bubble_sort(arr, n);

   int limited = 100;
    int limit = (n < limited) ? n : limited;
    for(int i = 0; i < limit; i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
