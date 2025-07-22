#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkString(char* s) {
    bool found_b = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'b') {
            found_b = true;
        } else if (found_b) {
            return false;
        }
    }
    return true;
}
