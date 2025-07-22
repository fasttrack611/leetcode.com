#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), cmp);
    int total_cost = 0;
    for (int i = 0; i < costSize; i++) {
        if ((i + 1) % 3 != 0) {
            total_cost += cost[i];
        }
    }
    return total_cost;
}
