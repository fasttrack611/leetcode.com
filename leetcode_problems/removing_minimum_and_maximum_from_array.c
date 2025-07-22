#include <stdio.h>
#include <limits.h>

int minimumDeletions(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int min_idx = -1;
    int max_idx = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
            min_idx = i;
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
            max_idx = i;
        }
    }

    int left = (min_idx < max_idx) ? min_idx : max_idx;
    int right = (min_idx > max_idx) ? min_idx : max_idx;

    int from_left = right + 1;
    int from_right = numsSize - left;
    int from_both = (left + 1) + (numsSize - right);

    int result = from_left;
    if (from_right < result) {
        result = from_right;
    }
    if (from_both < result) {
        result = from_both;
    }

    return result;
}
