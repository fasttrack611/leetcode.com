int sumOfBeauties(int* nums, int numsSize) {
    int* min_on_right = (int*)malloc(sizeof(int) * numsSize);
    min_on_right[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        min_on_right[i] = nums[i] < min_on_right[i + 1] ? nums[i] : min_on_right[i + 1];
    }

    int max_on_left = nums[0];
    int beauty_sum = 0;
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] > max_on_left && nums[i] < min_on_right[i + 1]) {
            beauty_sum += 2;
        } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
            beauty_sum += 1;
        }
        if (nums[i] > max_on_left) {
            max_on_left = nums[i];
        }
    }

    free(min_on_right);
    return beauty_sum;
}
