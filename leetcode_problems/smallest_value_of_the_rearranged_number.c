#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

long long smallestNumber(long long num) {
    if (num == 0) {
        return 0;
    }
    bool is_negative = num < 0;
    if (is_negative) {
        num = -num;
    }

    char s[20];
    sprintf(s, "%lld", num);
    int len = strlen(s);
    qsort(s, len, sizeof(char), cmp);

    if (is_negative) {
        char reversed_s[20];
        for (int i = 0; i < len; i++) {
            reversed_s[i] = s[len - 1 - i];
        }
        reversed_s[len] = '\0';
        return -atoll(reversed_s);
    } else {
        int i = 0;
        while (s[i] == '0') {
            i++;
        }
        char temp = s[0];
        s[0] = s[i];
        s[i] = temp;
        return atoll(s);
    }
}
