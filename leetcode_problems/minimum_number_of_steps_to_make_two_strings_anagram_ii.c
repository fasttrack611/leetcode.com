#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int minSteps(char* s, char* t) {
    int s_counts[26] = {0};
    int t_counts[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        s_counts[s[i] - 'a']++;
    }
    for (int i = 0; t[i] != '\0'; i++) {
        t_counts[t[i] - 'a']++;
    }

    int steps = 0;
    for (int i = 0; i < 26; i++) {
        steps += abs(s_counts[i] - t_counts[i]);
    }

    return steps;
}
