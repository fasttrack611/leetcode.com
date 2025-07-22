#include <stdio.h>
#include <stdlib.h>

int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int* counts = (int*)calloc(1001, sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsColSize[i]; ++j) {
            counts[nums[i][j]]++;
        }
    }

    int* result = (int*)malloc(1001 * sizeof(int));
    *returnSize = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (counts[i] == numsSize) {
            result[(*returnSize)++] = i;
        }
    }

    free(counts);
    return result;
}
