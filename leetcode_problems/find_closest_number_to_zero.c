#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findClosestNumber(int* nums, int numsSize) {
    int closest = INT_MAX;
    int result = 0;

    for (int i = 0; i < numsSize; ++i) {
        int absVal = abs(nums[i]);
        if (absVal < closest) {
            closest = absVal;
            result = nums[i];
        } else if (absVal == closest && nums[i] > result) {
            result = nums[i];
        }
    }
    return result;
}

int main() {
    // You can modify this array to test with different inputs
    int nums[] = { -10, -3, 2, 5, -2, 3 };
    int size = sizeof(nums) / sizeof(nums[0]);

    int closest = findClosestNumber(nums, size);
    printf("Closest number to zero: %d\n", closest);

    return 0;
}
