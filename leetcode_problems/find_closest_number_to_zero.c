#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findClosestNumber(int* nums, int numsSize) {
    int closest = INT_MAX;
    int result = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (abs(nums[i]) < closest) {
            closest = abs(nums[i]);
            result = nums[i];
        } else if (abs(nums[i]) == closest) {
            if (nums[i] > result) {
                result = nums[i];
            }
        }
    }
    return result;
}
