#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addSpaces(char* s, int* spaces, int spacesSize) {
    int s_len = strlen(s);
    int result_len = s_len + spacesSize;
    char* result = (char*)malloc(result_len + 1);
    int s_ptr = 0;
    int space_ptr = 0;
    int result_ptr = 0;

    while (s_ptr < s_len) {
        if (space_ptr < spacesSize && s_ptr == spaces[space_ptr]) {
            result[result_ptr++] = ' ';
            space_ptr++;
        }
        result[result_ptr++] = s[s_ptr++];
    }

    result[result_ptr] = '\0';
    return result;
}
