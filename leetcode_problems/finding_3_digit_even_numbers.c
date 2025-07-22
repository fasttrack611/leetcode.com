#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int counts[10] = {0};
    for (int i = 0; i < digitsSize; i++) {
        counts[digits[i]]++;
    }

    int* result = (int*)malloc(900 * sizeof(int));
    *returnSize = 0;

    for (int i = 100; i < 1000; i += 2) {
        int d1 = i / 100;
        int d2 = (i / 10) % 10;
        int d3 = i % 10;
        int temp_counts[10] = {0};
        temp_counts[d1]++;
        temp_counts[d2]++;
        temp_counts[d3]++;
        bool possible = true;
        for (int j = 0; j < 10; j++) {
            if (temp_counts[j] > counts[j]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}
