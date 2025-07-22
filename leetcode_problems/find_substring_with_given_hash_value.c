#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

char* subStrHash(char* s, int power_val, int modulo, int k, int hashValue) {
    int n = strlen(s);
    long long pk = power(power_val, k, modulo);
    long long current_hash = 0;

    for (int i = n - 1; i >= n - k; i--) {
        current_hash = (current_hash * power_val + (s[i] - 'a' + 1)) % modulo;
    }

    int result_index = -1;
    if (current_hash == hashValue) {
        result_index = n - k;
    }

    for (int i = n - k - 1; i >= 0; i--) {
        current_hash = (current_hash * power_val - (s[i + k] - 'a' + 1) * pk % modulo + modulo) % modulo;
        current_hash = (current_hash + (s[i] - 'a' + 1)) % modulo;
        if (current_hash == hashValue) {
            result_index = i;
        }
    }

    char* result = (char*)malloc(k + 1);
    strncpy(result, s + result_index, k);
    result[k] = '\0';
    return result;
}
