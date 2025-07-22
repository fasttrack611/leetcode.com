#include <stdio.h>

int minBitFlips(int start, int goal) {
    int xor_result = start ^ goal;
    int flips = 0;
    while (xor_result > 0) {
        flips += xor_result & 1;
        xor_result >>= 1;
    }
    return flips;
}
