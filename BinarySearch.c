#include <stdio.h>
int BinarySearch(int arr[],int size,int target){
    int low = 0;
    int high = size - 1;
    
    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[mid] == target){
            return mid;}
        else if (arr[mid] < target){
            low = mid + 1;
        }
        else {
         high = mid - 1;
        }

    }
    return -1;
}
int main(){

int arr[] = {1,2,3,4,5,6,7,67};
int size = sizeof(arr) / sizeof(arr[0]);
int target = 67;

int result = BinarySearch(arr,size,target);

printf("%d Index\n",result);
printf("%d Target Number",target);
    return 0;
}