#include <stdio.h>
#include <stdbool.h>

bool is_balanced(int n) {
    int counts[10] = {0};
    int temp = n;
    while (temp > 0) {
        counts[temp % 10]++;
        temp /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0 && counts[i] != i) {
            return false;
        }
    }
    return true;
}

int nextBeautifulNumber(int n) {
    while (1) {
        n++;
        if (is_balanced(n)) {
            return n;
        }
    }
}
