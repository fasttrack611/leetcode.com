int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    qsort(nums, numsSize, sizeof(int), [](const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    });

    int left = 0;
    int right = numsSize - 1;
    int i = 0;
    while (left <= right) {
        if (i % 2 == 0) {
            result[i] = nums[left];
            left++;
        } else {
            result[i] = nums[right];
            right--;
        }
        i++;
    }

    return result;
}
