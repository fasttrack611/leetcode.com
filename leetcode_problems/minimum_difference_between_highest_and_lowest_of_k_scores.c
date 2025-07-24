int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (k == 1) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), compare);
    int min_diff = INT_MAX;
    for (int i = 0; i <= numsSize - k; i++) {
        int diff = nums[i + k - 1] - nums[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    return min_diff;
}
