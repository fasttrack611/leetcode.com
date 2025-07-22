#include <stdio.h>

long long getDescentPeriods(int* prices, int pricesSize) {
    long long count = 1;
    long long result = 1;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] == prices[i - 1] - 1) {
            count++;
        } else {
            count = 1;
        }
        result += count;
    }
    return result;
}
