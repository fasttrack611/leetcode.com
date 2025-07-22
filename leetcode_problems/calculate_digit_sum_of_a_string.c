#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* digitSum(char* s, int k) {
    while (strlen(s) > k) {
        char* new_s = (char*)malloc(strlen(s) + 1);
        new_s[0] = '\0';
        int i = 0;
        while (i < strlen(s)) {
            int sum = 0;
            for (int j = 0; j < k && i + j < strlen(s); ++j) {
                sum += s[i + j] - '0';
            }
            char temp[10];
            sprintf(temp, "%d", sum);
            strcat(new_s, temp);
            i += k;
        }
        s = new_s;
    }
    return s;
}
