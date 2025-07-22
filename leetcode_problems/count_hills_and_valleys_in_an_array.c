#include <stdio.h>

int countHillValley(int* nums, int numsSize) {
    if (numsSize < 3) {
        return 0;
    }

    int count = 0;
    int left = nums[0];

    for (int i = 1; i < numsSize - 1; i++) {
        if ((nums[i] > left && nums[i] > nums[i + 1]) || (nums[i] < left && nums[i] < nums[i + 1])) {
            count++;
        }
        if (nums[i] != nums[i+1]) {
            left = nums[i];
        }
    }

    return count;
}
