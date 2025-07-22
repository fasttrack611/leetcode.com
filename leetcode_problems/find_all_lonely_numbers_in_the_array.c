#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* findLonely(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);

    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    if (numsSize == 1) {
        result[(*returnSize)++] = nums[0];
        return result;
    }

    if (nums[1] > nums[0] + 1) {
        result[(*returnSize)++] = nums[0];
    }

    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i - 1] < nums[i] - 1 && nums[i + 1] > nums[i] + 1) {
            result[(*returnSize)++] = nums[i];
        }
    }

    if (nums[numsSize - 2] < nums[numsSize - 1] - 1) {
        result[(*returnSize)++] = nums[numsSize - 1];
    }

    return result;
}
