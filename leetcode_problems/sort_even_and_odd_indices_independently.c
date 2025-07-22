#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int cmp_desc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int even_size = (numsSize + 1) / 2;
    int odd_size = numsSize / 2;
    int* even_indices = (int*)malloc(even_size * sizeof(int));
    int* odd_indices = (int*)malloc(odd_size * sizeof(int));
    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            even_indices[even_count++] = nums[i];
        } else {
            odd_indices[odd_count++] = nums[i];
        }
    }

    qsort(even_indices, even_size, sizeof(int), cmp_asc);
    qsort(odd_indices, odd_size, sizeof(int), cmp_desc);

    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    even_count = 0;
    odd_count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            result[i] = even_indices[even_count++];
        } else {
            result[i] = odd_indices[odd_count++];
        }
    }

    free(even_indices);
    free(odd_indices);
    return result;
}
