#include <stdio.h>
#include <stdlib.h>

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int less_count = 0;
    int equal_count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) {
            less_count++;
        } else if (nums[i] == pivot) {
            equal_count++;
        }
    }

    int less_ptr = 0;
    int equal_ptr = less_count;
    int greater_ptr = less_count + equal_count;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) {
            result[less_ptr++] = nums[i];
        } else if (nums[i] == pivot) {
            result[equal_ptr++] = nums[i];
        } else {
            result[greater_ptr++] = nums[i];
        }
    }

    return result;
}
