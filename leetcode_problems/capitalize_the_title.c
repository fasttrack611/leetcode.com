#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* capitalizeTitle(char* title) {
    int len = strlen(title);
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (i == len || title[i] == ' ') {
            if (i - start > 2) {
                title[start] = toupper(title[start]);
            }
            start = i + 1;
        } else {
            title[i] = tolower(title[i]);
        }
    }
    return title;
}
