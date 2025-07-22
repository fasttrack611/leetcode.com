#include <stdio.h>
#include <stdbool.h>

int findFinalValue(int* nums, int numsSize, int original) {
    bool found[1001] = {false};
    for (int i = 0; i < numsSize; i++) {
        found[nums[i]] = true;
    }

    while (original <= 1000 && found[original]) {
        original *= 2;
    }

    return original;
}
