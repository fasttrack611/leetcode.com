#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_valid(char* word) {
    int len = strlen(word);
    if (len == 0) {
        return false;
    }
    int hyphens = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(word[i])) {
            return false;
        }
        if (word[i] == '-') {
            if (hyphens > 0 || i == 0 || i == len - 1 || !isalpha(word[i - 1]) || !isalpha(word[i + 1])) {
                return false;
            }
            hyphens++;
        }
        if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
            if (i != len - 1) {
                return false;
            }
        }
    }
    return true;
}

int countValidWords(char* sentence) {
    int count = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        if (is_valid(token)) {
            count++;
        }
        token = strtok(NULL, " ");
    }
    return count;
}
