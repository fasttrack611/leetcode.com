#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    bool* is_distant = (bool*)calloc(numsSize, sizeof(bool));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            for (int j = 0; j < numsSize; j++) {
                if (abs(i - j) <= k) {
                    is_distant[j] = true;
                }
            }
        }
    }

    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (is_distant[i]) {
            result[(*returnSize)++] = i;
        }
    }

    free(is_distant);
    return result;
}
