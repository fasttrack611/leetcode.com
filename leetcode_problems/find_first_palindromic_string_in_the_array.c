#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

char* firstPalindrome(char** words, int wordsSize) {
    for (int i = 0; i < wordsSize; i++) {
        if (is_palindrome(words[i])) {
            return words[i];
        }
    }
    return "";
}
