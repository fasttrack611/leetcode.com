#include <stdio.h>

int mostFrequent(int* nums, int numsSize, int key) {
    int counts[1001] = {0};
    int max_count = 0;
    int target = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == key) {
            counts[nums[i + 1]]++;
            if (counts[nums[i + 1]] > max_count) {
                max_count = counts[nums[i + 1]];
                target = nums[i + 1];
            }
        }
    }

    return target;
}
