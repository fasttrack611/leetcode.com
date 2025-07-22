#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minimumAverageDifference(int* nums, int numsSize) {
    long long total_sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        total_sum += nums[i];
    }

    int min_avg_diff = INT_MAX;
    int result_index = -1;
    long long left_sum = 0;

    for (int i = 0; i < numsSize; ++i) {
        left_sum += nums[i];
        long long right_sum = total_sum - left_sum;
        long long left_avg = left_sum / (i + 1);
        long long right_avg = (numsSize - 1 - i) == 0 ? 0 : right_sum / (numsSize - 1 - i);
        int avg_diff = abs(left_avg - right_avg);

        if (avg_diff < min_avg_diff) {
            min_avg_diff = avg_diff;
            result_index = i;
        }
    }

    return result_index;
}
