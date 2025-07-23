#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    int* map = (int*)calloc(101, sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        map[nums1[i]] |= 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        map[nums2[i]] |= 2;
    }
    for (int i = 0; i < nums3Size; i++) {
        map[nums3[i]] |= 4;
    }

    int* res = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;
    for (int i = 1; i <= 100; i++) {
        if (map[i] == 3 || map[i] == 5 || map[i] == 6 || map[i] == 7) {
            res[(*returnSize)++] = i;
        }
    }

    free(map);
    return res;
}

int main() {
    int nums1[] = {1, 1, 3, 2};
    int nums2[] = {2, 3};
    int nums3[] = {3};
    int returnSize;
    int* res = twoOutOfThree(nums1, 4, nums2, 2, nums3, 1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
    return 0;
}
