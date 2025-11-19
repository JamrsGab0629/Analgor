#include <stdio.h>

#define SIZE 7

int digit_sum(int num){
    int sums = 0;

    while(num > 0){
        sums += num % 10;
        num = num / 10;
    }
    return sums;
}

void sum_of_matching_sums(int arr[],int result[],int n,int *res_size){
    int digit_sums[SIZE];

    for(int i = 0; i < n; i++){
        digit_sums[i] = digit_sum(arr[i]);
    }
    *res_size = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(digit_sums[i] == digit_sums[j]){
                result[*res_size] = arr[i] + arr[j];
                 (*res_size)++;
                  break;
                }
            }
        }
    
}


int main(){
int arr[SIZE] = {12, 4, 234, 13, 111, 8, 22};
int result[SIZE];
int res_size;

sum_of_matching_sums(arr,result,SIZE,&res_size);

for(int i = 0; i < res_size; i++){
    printf("%d,",result[i]);
}
}