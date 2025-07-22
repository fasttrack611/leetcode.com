#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    memset(result, -1, numsSize * sizeof(int));

    if (2 * k + 1 > numsSize) {
        return result;
    }

    long long sum = 0;
    for (int i = 0; i < 2 * k + 1; i++) {
        sum += nums[i];
    }

    result[k] = sum / (2 * k + 1);

    for (int i = k + 1; i < numsSize - k; i++) {
        sum = sum - nums[i - k - 1] + nums[i + k];
        result[i] = sum / (2 * k + 1);
    }

    return result;
}
