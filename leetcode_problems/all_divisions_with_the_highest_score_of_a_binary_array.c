#include <stdio.h>
#include <stdlib.h>

int* maxScoreIndices(int* nums, int numsSize, int* returnSize) {
    int total_ones = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            total_ones++;
        }
    }

    int max_score = -1;
    int* result = (int*)malloc((numsSize + 1) * sizeof(int));
    *returnSize = 0;
    int zeros_left = 0;
    int ones_right = total_ones;

    for (int i = 0; i <= numsSize; i++) {
        int score = zeros_left + ones_right;
        if (score > max_score) {
            max_score = score;
            *returnSize = 0;
            result[(*returnSize)++] = i;
        } else if (score == max_score) {
            result[(*returnSize)++] = i;
        }

        if (i < numsSize) {
            if (nums[i] == 0) {
                zeros_left++;
            } else {
                ones_right--;
            }
        }
    }

    return result;
}
