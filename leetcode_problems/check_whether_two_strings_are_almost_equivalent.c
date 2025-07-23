#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkAlmostEquivalent(char* word1, char* word2) {
    int counts1[26] = {0};
    int counts2[26] = {0};

    for (int i = 0; word1[i] != '\0'; i++) {
        counts1[word1[i] - 'a']++;
    }
    for (int i = 0; word2[i] != '\0'; i++) {
        counts2[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (abs(counts1[i] - counts2[i]) > 3) {
            return false;
        }
    }

    return true;
}
