#include <stdio.h>

//Bubble sort
int main(){

    int n =5;
    int j,i,temp;
    int arr[5] = {9,6,4,3,7};

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }

        }
    }
printf("orig\n");
for(i = 0; i < n; i++){
    printf("%d",arr[i]);
}
    return 0;
}