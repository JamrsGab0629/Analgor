#include <stdio.h>

int bubblesort(int arr[],int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                
            }
        }
    }

}
int binarysearch(int arr[],int size,int target){
    int low = 0;
    int high = size - 1;

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[mid] == target){
            return mid;}
        else if (arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        }

return -1;
    }

int main(){
    int arr[] = {9,3,7,6,5,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    bubblesort(arr,size);
    int result = binarysearch(arr,size,target);
    
     
    for(int i = 0; i < size; i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
    printf("%d",result);


 return 0;
}