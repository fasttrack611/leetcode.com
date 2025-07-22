#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumCardPickup(int* cards, int cardsSize) {
    int min_dist = 100001;
    int* last_pos = (int*)malloc(1000001 * sizeof(int));
    memset(last_pos, -1, 1000001 * sizeof(int));

    for (int i = 0; i < cardsSize; ++i) {
        if (last_pos[cards[i]] != -1) {
            int dist = i - last_pos[cards[i]] + 1;
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
        last_pos[cards[i]] = i;
    }

    free(last_pos);
    return min_dist == 100001 ? -1 : min_dist;
}
