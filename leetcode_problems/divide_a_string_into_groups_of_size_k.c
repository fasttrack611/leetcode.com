#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s);
    *returnSize = (len + k - 1) / k;
    char** result = (char**)malloc(*returnSize * sizeof(char*));

    for (int i = 0; i < *returnSize; i++) {
        result[i] = (char*)malloc((k + 1) * sizeof(char));
        int j;
        for (j = 0; j < k; j++) {
            if (i * k + j < len) {
                result[i][j] = s[i * k + j];
            } else {
                result[i][j] = fill;
            }
        }
        result[i][j] = '\0';
    }

    return result;
}
