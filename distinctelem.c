#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findlargestelement(int arr[],int size){
    int max = arr[0];
    for(int i = 0; i < size; i++){
      if(arr[i] > max){
        max = arr[i];
      }
    }
    
    bool found = 0;
int second = -1000000000;
    for(int i = 0; i < size; i++){
        if(arr[i] < max && arr[i] > second){
            second = arr[i];
            found = true;

        }

    }
   if(found){
    return second;
   }
   else {
   return -1;}
}
int main(){
    int arr[] = {1,3,5,2,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = findlargestelement(arr,size);

    printf("%d",result);

    
    return 0;
}
