#include <stdio.h>
#include <string.h>

int mostWordsFound(char** sentences, int sentencesSize) {
    int max_words = 0;
    for (int i = 0; i < sentencesSize; i++) {
        int words = 1;
        for (int j = 0; sentences[i][j] != '\0'; j++) {
            if (sentences[i][j] == ' ') {
                words++;
            }
        }
        if (words > max_words) {
            max_words = words;
        }
    }
    return max_words;
}
