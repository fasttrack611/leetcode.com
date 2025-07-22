#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** cellsInRange(char* s, int* returnSize) {
    char c1 = s[0], c2 = s[3];
    char r1 = s[1], r2 = s[4];

    *returnSize = (c2 - c1 + 1) * (r2 - r1 + 1);
    char** result = (char**)malloc(*returnSize * sizeof(char*));
    int index = 0;
    for (char c = c1; c <= c2; c++) {
        for (char r = r1; r <= r2; r++) {
            result[index] = (char*)malloc(3 * sizeof(char));
            result[index][0] = c;
            result[index][1] = r;
            result[index][2] = '\0';
            index++;
        }
    }

    return result;
}
