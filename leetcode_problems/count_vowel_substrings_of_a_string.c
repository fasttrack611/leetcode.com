#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countVowelSubstrings(char* word) {
    int count = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            bool a = false, e = false, i_vowel = false, o = false, u = false;
            bool non_vowel = false;
            for (int k = i; k <= j; k++) {
                if (!is_vowel(word[k])) {
                    non_vowel = true;
                    break;
                }
                if (word[k] == 'a') a = true;
                if (word[k] == 'e') e = true;
                if (word[k] == 'i') i_vowel = true;
                if (word[k] == 'o') o = true;
                if (word[k] == 'u') u = true;
            }
            if (!non_vowel && a && e && i_vowel && o && u) {
                count++;
            }
        }
    }
    return count;
}
