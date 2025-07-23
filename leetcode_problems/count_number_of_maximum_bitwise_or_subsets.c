#include <stdio.h>
#include <stdlib.h>

void findSubsets(int* nums, int numsSize, int index, int currentOR, int* maxOR, int* count) {
    if (index == numsSize) {
        if (currentOR > *maxOR) {
            *maxOR = currentOR;
            *count = 1;
        } else if (currentOR == *maxOR) {
            (*count)++;
        }
        return;
    }

    findSubsets(nums, numsSize, index + 1, currentOR | nums[index], maxOR, count);
    findSubsets(nums, numsSize, index + 1, currentOR, maxOR, count);
}

int countMaxOrSubsets(int* nums, int numsSize) {
    int maxOR = 0;
    int count = 0;
    findSubsets(nums, numsSize, 0, 0, &maxOR, &count);
    return count;
}

int main() {
    int nums[] = {3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("The number of subsets with maximum bitwise OR is: %d\n", countMaxOrSubsets(nums, numsSize));
    return 0;
}
