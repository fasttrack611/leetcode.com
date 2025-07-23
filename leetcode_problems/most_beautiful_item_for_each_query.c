#include <stdio.h>
#include <stdlib.h>

int cmp_items(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    qsort(items, itemsSize, sizeof(int*), cmp_items);
    int* max_beauty = (int*)malloc(itemsSize * sizeof(int));
    max_beauty[0] = items[0][1];
    for (int i = 1; i < itemsSize; i++) {
        max_beauty[i] = (items[i][1] > max_beauty[i - 1]) ? items[i][1] : max_beauty[i - 1];
    }

    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int left = 0, right = itemsSize - 1;
        int best_index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= queries[i]) {
                best_index = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        result[i] = (best_index == -1) ? 0 : max_beauty[best_index];
    }

    free(max_beauty);
    return result;
}
