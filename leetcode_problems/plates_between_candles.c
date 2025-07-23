#include <stdio.h>
#include <stdlib.h>

int* platesBetweenCandles(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int len = strlen(s);
    int* left = (int*)malloc(len * sizeof(int));
    int* right = (int*)malloc(len * sizeof(int));
    int* prefix_sum = (int*)malloc(len * sizeof(int));

    int last = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '|') {
            last = i;
        }
        left[i] = last;
    }

    last = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '|') {
            last = i;
        }
        right[i] = last;
    }

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            count++;
        }
        prefix_sum[i] = count;
    }

    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int l_candle = right[l];
        int r_candle = left[r];
        if (l_candle == -1 || r_candle == -1 || l_candle >= r_candle) {
            result[i] = 0;
        } else {
            result[i] = prefix_sum[r_candle] - prefix_sum[l_candle];
        }
    }

    free(left);
    free(right);
    free(prefix_sum);
    return result;
}
