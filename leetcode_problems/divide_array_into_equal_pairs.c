#include <stdio.h>
#include <stdbool.h>

bool divideArray(int* nums, int numsSize) {
    int counts[501] = {0};
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
    }

    for (int i = 1; i <= 500; i++) {
        if (counts[i] % 2 != 0) {
            return false;
        }
    }

    return true;
}
