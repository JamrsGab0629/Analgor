#include <stdio.h>
int linearsearch(int arr[],int target,int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }

}
int main(){

int arr[] = {5,6,7,8,9};
int n = sizeof(arr) / sizeof(arr[0]);
int target = 8;
int result = linearsearch(arr,target,n);

printf("%d",result);
    return 0;
}