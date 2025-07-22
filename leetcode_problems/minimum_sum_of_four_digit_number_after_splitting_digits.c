#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int minimumSum(int num) {
    char s[5];
    sprintf(s, "%d", num);
    qsort(s, 4, sizeof(char), cmp);
    int num1 = (s[0] - '0') * 10 + (s[2] - '0');
    int num2 = (s[1] - '0') * 10 + (s[3] - '0');
    return num1 + num2;
}
