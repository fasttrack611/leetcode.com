#include <stdio.h>
#include <stdlib.h>

int maxDistance(int* colors, int colorsSize) {
    int max_dist = 0;
    for (int i = 0; i < colorsSize; i++) {
        for (int j = i + 1; j < colorsSize; j++) {
            if (colors[i] != colors[j]) {
                int dist = abs(i - j);
                if (dist > max_dist) {
                    max_dist = dist;
                }
            }
        }
    }
    return max_dist;
}
