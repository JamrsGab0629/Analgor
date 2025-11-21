#include <stdio.h>

int digit_sum(int num) {
    int s = 0;
    while (num > 0) {
        s += num % 10;
        num /= 10;
    }
    return s;
}

void sum_matching(int nums[], int n, int results[], int *res_size) {
    int last_seen[100];
    for (int i = 0; i < 100; i++) last_seen[i] = -1;

    *res_size = 0;

    for (int i = 0; i < n; i++) {
        int dsum = digit_sum(nums[i]);
        if (last_seen[dsum] != -1) {
            int prev_index = last_seen[dsum];
            results[*res_size] = nums[prev_index] + nums[i];
            (*res_size)++;
        }
        last_seen[dsum] = i;
    }
}

int main() {
    int nums[] = {12, 4, 234, 13, 111, 8, 22};
    int n = sizeof(nums) / sizeof(nums[0]);
    int results[100];
    int res_size;

    sum_matching(nums, n, results, &res_size);

    printf("Output: [");
    for (int i = 0; i < res_size; i++) {
        printf("%d", results[i]);
        if (i < res_size - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}
    
