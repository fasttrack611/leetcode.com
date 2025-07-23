#include <stdio.h>
#include <string.h>

long long countVowels(char* word) {
    long long count = 0;
    long long len = strlen(word);
    for (long long i = 0; i < len; i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            count += (i + 1) * (len - i);
        }
    }
    return count;
}
