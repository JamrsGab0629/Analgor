#include <stdio.h>
#include <stdbool.h>

int findmissingelem(int arr[],int n){
   
   
    for(int i = 1; i <= n + 1; i++){
          bool found = false; 
           for(int j = 0; j < n; j++){
            if(arr[j] == i){    
                found = true;
                break;
            }

           }
            if(!found){
        return i;
    }
    }
    return -1;
    
}

int main(){
    int arr[] = {1,2,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = findmissingelem(arr,n);
    printf("%d",result);

    return 0;
}
