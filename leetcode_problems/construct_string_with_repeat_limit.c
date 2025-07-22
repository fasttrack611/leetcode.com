#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* repeatLimitedString(char* s, int repeatLimit) {
    int counts[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        counts[s[i] - 'a']++;
    }

    char* result = (char*)malloc(strlen(s) + 1);
    int index = 0;

    while (1) {
        int i = 25;
        while (i >= 0 && counts[i] == 0) {
            i--;
        }
        if (i < 0) {
            break;
        }

        int repeat = (counts[i] < repeatLimit) ? counts[i] : repeatLimit;
        for (int j = 0; j < repeat; j++) {
            result[index++] = 'a' + i;
        }
        counts[i] -= repeat;

        if (counts[i] > 0) {
            int k = i - 1;
            while (k >= 0 && counts[k] == 0) {
                k--;
            }
            if (k < 0) {
                break;
            }
            result[index++] = 'a' + k;
            counts[k]--;
        }
    }

    result[index] = '\0';
    return result;
}
