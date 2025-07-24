int compare(const void* a, const void* b) {
    char* str1 = *(char**)a;
    char* str2 = *(char**)b;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return len1 - len2;
    }
    return strcmp(str1, str2);
}

char* kthLargestNumber(char** nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(char*), compare);
    return nums[numsSize - k];
}
