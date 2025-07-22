#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
    return (*(double*)b - *(double*)a);
}

int minOperations(int* nums, int numsSize) {
    double sum = 0;
    double* double_nums = (double*)malloc(numsSize * sizeof(double));
    for (int i = 0; i < numsSize; i++) {
        double_nums[i] = (double)nums[i];
        sum += double_nums[i];
    }

    double target = sum / 2.0;
    int operations = 0;

    qsort(double_nums, numsSize, sizeof(double), cmpfunc);

    while (sum > target) {
        double half = double_nums[0] / 2.0;
        sum -= half;
        double_nums[0] = half;
        operations++;
        qsort(double_nums, numsSize, sizeof(double), cmpfunc);
    }

    free(double_nums);
    return operations;
}
