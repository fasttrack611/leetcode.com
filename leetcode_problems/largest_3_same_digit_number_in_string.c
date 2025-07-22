#include <string.h>
#include <stdio.h>

char* largestGoodInteger(char* num) {
    int len = strlen(num);
    if (len < 3) {
        return "";
    }

    int max_digit = -1;

    for (int i = 0; i <= len - 3; ++i) {
        if (num[i] == num[i+1] && num[i] == num[i+2]) {
            if (num[i] - '0' > max_digit) {
                max_digit = num[i] - '0';
            }
        }
    }

    if (max_digit == -1) {
        return "";
    }

    char* result = (char*)malloc(4 * sizeof(char));
    sprintf(result, "%d%d%d", max_digit, max_digit, max_digit);
    return result;
}
