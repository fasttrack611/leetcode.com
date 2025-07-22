#include <stdio.h>
#include <string.h>

int prefixCount(char** words, int wordsSize, char* pref) {
    int count = 0;
    for (int i = 0; i < wordsSize; ++i) {
        if (strncmp(pref, words[i], strlen(pref)) == 0) {
            count++;
        }
    }
    return count;
}
