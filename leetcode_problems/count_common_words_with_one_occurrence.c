#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* word;
    int count;
} WordCount;

int countWords(char** words1, int words1Size, char** words2, int words2Size) {
    WordCount* counts1 = (WordCount*)malloc(words1Size * sizeof(WordCount));
    int counts1Size = 0;
    for (int i = 0; i < words1Size; i++) {
        bool found = false;
        for (int j = 0; j < counts1Size; j++) {
            if (strcmp(words1[i], counts1[j].word) == 0) {
                counts1[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            counts1[counts1Size].word = words1[i];
            counts1[counts1Size].count = 1;
            counts1Size++;
        }
    }

    WordCount* counts2 = (WordCount*)malloc(words2Size * sizeof(WordCount));
    int counts2Size = 0;
    for (int i = 0; i < words2Size; i++) {
        bool found = false;
        for (int j = 0; j < counts2Size; j++) {
            if (strcmp(words2[i], counts2[j].word) == 0) {
                counts2[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            counts2[counts2Size].word = words2[i];
            counts2[counts2Size].count = 1;
            counts2Size++;
        }
    }

    int result = 0;
    for (int i = 0; i < counts1Size; i++) {
        if (counts1[i].count == 1) {
            for (int j = 0; j < counts2Size; j++) {
                if (counts2[j].count == 1 && strcmp(counts1[i].word, counts2[j].word) == 0) {
                    result++;
                    break;
                }
            }
        }
    }

    free(counts1);
    free(counts2);
    return result;
}
