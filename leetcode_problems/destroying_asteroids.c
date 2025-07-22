#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    qsort(asteroids, asteroidsSize, sizeof(int), cmp);
    long long current_mass = mass;
    for (int i = 0; i < asteroidsSize; i++) {
        if (current_mass >= asteroids[i]) {
            current_mass += asteroids[i];
        } else {
            return false;
        }
    }
    return true;
}
