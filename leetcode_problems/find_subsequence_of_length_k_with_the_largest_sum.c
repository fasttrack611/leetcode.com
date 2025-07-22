#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Num;

int cmp_val(const void* a, const void* b) {
    return ((Num*)b)->val - ((Num*)a)->val;
}

int cmp_index(const void* a, const void* b) {
    return ((Num*)a)->index - ((Num*)b)->index;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    Num* indexed_nums = (Num*)malloc(numsSize * sizeof(Num));
    for (int i = 0; i < numsSize; i++) {
        indexed_nums[i].val = nums[i];
        indexed_nums[i].index = i;
    }

    qsort(indexed_nums, numsSize, sizeof(Num), cmp_val);
    qsort(indexed_nums, k, sizeof(Num), cmp_index);

    int* result = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    for (int i = 0; i < k; i++) {
        result[i] = indexed_nums[i].val;
    }

    free(indexed_nums);
    return result;
}
