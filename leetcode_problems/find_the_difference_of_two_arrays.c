#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    bool set1[2001] = {false};
    bool set2[2001] = {false};

    for (int i = 0; i < nums1Size; i++) {
        set1[nums1[i] + 1000] = true;
    }
    for (int i = 0; i < nums2Size; i++) {
        set2[nums2[i] + 1000] = true;
    }

    int** result = (int**)malloc(2 * sizeof(int*));
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));

    result[0] = (int*)malloc(nums1Size * sizeof(int));
    (*returnColumnSizes)[0] = 0;
    for (int i = 0; i < nums1Size; i++) {
        if (!set2[nums1[i] + 1000]) {
            bool found = false;
            for (int j = 0; j < (*returnColumnSizes)[0]; j++) {
                if (result[0][j] == nums1[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[0][(*returnColumnSizes)[0]++] = nums1[i];
            }
        }
    }

    result[1] = (int*)malloc(nums2Size * sizeof(int));
    (*returnColumnSizes)[1] = 0;
    for (int i = 0; i < nums2Size; i++) {
        if (!set1[nums2[i] + 1000]) {
            bool found = false;
            for (int j = 0; j < (*returnColumnSizes)[1]; j++) {
                if (result[1][j] == nums2[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[1][(*returnColumnSizes)[1]++] = nums2[i];
            }
        }
    }

    return result;
}
