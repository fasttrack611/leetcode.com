#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int arrSize;
} RangeFreqQuery;

RangeFreqQuery* rangeFreqQueryCreate(int* arr, int arrSize) {
    RangeFreqQuery* obj = (RangeFreqQuery*)malloc(sizeof(RangeFreqQuery));
    obj->arr = (int*)malloc(arrSize * sizeof(int));
    memcpy(obj->arr, arr, arrSize * sizeof(int));
    obj->arrSize = arrSize;
    return obj;
}

int rangeFreqQueryQuery(RangeFreqQuery* obj, int left, int right, int value) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (obj->arr[i] == value) {
            count++;
        }
    }
    return count;
}

void rangeFreqQueryFree(RangeFreqQuery* obj) {
    free(obj->arr);
    free(obj);
}
