#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDigit(char* number, char digit) {
    int len = strlen(number);
    char* max_num = "";
    int last_pos = -1;

    for (int i = 0; i < len; ++i) {
        if (number[i] == digit) {
            last_pos = i;
        }
    }

    for (int i = 0; i < len; ++i) {
        if (number[i] == digit) {
            char* temp = (char*)malloc(len * sizeof(char));
            strncpy(temp, number, i);
            temp[i] = '\0';
            strcat(temp, number + i + 1);

            if (strcmp(temp, max_num) > 0) {
                max_num = temp;
            } else {
                free(temp);
            }
        }
    }
    return max_num;
}
