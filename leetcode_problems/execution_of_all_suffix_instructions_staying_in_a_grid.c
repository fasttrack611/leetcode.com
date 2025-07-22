#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* executeInstructions(int n, int* startPos, int startPosSize, char* s, int sSize, int* returnSize) {
    *returnSize = sSize;
    int* result = (int*)malloc(sSize * sizeof(int));

    for (int i = 0; i < sSize; i++) {
        int r = startPos[0];
        int c = startPos[1];
        int count = 0;
        for (int j = i; j < sSize; j++) {
            if (s[j] == 'R') {
                c++;
            } else if (s[j] == 'L') {
                c--;
            } else if (s[j] == 'U') {
                r--;
            } else {
                r++;
            }
            if (r >= 0 && r < n && c >= 0 && c < n) {
                count++;
            } else {
                break;
            }
        }
        result[i] = count;
    }

    return result;
}
