#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void random_array(int arr[], int size){
    int n = size;
    for(int i=0; i < size; i++){
        arr[i] = rand() % 100; 
    }
}

void sort_array(int arr[], int size){
    for(int i=0; i < size-1; i++){
        for(int j=0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){ 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int n = 100;
    int arr[n];
    random_array(arr, n);
    int size = sizeof(arr)/sizeof(arr[0]);  
    sort_array(arr, size);
   for(int i=0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
