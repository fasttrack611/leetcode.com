#include <stdio.h>
#include <stdlib.h>

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int pos_ptr = 0;
    int neg_ptr = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[pos_ptr] = nums[i];
            pos_ptr += 2;
        } else {
            result[neg_ptr] = nums[i];
            neg_ptr += 2;
        }
    }

    return result;
}
