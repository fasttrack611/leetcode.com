#include <stdio.h>
#include <stdlib.h>

long long* sumOfThree(long long num, int* returnSize) {
    if (num % 3 != 0) {
        *returnSize = 0;
        return NULL;
    }

    long long* result = (long long*)malloc(3 * sizeof(long long));
    *returnSize = 3;
    long long x = num / 3;
    result[0] = x - 1;
    result[1] = x;
    result[2] = x + 1;
    return result;
}
