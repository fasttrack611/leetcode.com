#include <stdio.h>
#include <string.h>

int minSwaps(int* nums, int numsSize) {
    int ones = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            ones++;
        }
    }

    if (ones == 0 || ones == numsSize) {
        return 0;
    }

    int window_zeros = 0;
    for (int i = 0; i < ones; i++) {
        if (nums[i] == 0) {
            window_zeros++;
        }
    }

    int min_swaps = window_zeros;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == 0) {
            window_zeros--;
        }
        if (nums[(i + ones - 1) % numsSize] == 0) {
            window_zeros++;
        }
        if (window_zeros < min_swaps) {
            min_swaps = window_zeros;
        }
    }

    return min_swaps;
}
