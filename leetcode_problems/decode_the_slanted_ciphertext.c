#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* decodeCiphertext(char* encodedText, int rows) {
    int len = strlen(encodedText);
    if (len == 0) {
        return "";
    }
    int cols = len / rows;
    char* result = (char*)malloc(len + 1);
    int result_ptr = 0;

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows && i + j < cols; j++) {
            result[result_ptr++] = encodedText[j * cols + i + j];
        }
    }

    while (result_ptr > 0 && result[result_ptr - 1] == ' ') {
        result_ptr--;
    }
    result[result_ptr] = '\0';

    return result;
}
