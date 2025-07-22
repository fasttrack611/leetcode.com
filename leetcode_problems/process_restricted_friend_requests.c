#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find_set(int v, int* parent) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v], parent);
}

void unite_sets(int a, int b, int* parent) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        parent[b] = a;
    }
}

bool* friendRequests(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize, int** requests, int requestsSize, int* requestsColSize, int* returnSize) {
    *returnSize = requestsSize;
    bool* result = (bool*)malloc(requestsSize * sizeof(bool));
    int* parent = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < requestsSize; i++) {
        for (int j = 0; j < n; j++) {
            parent[j] = j;
        }
        for (int j = 0; j < i; j++) {
            if (result[j]) {
                unite_sets(requests[j][0], requests[j][1], parent);
            }
        }

        int u = requests[i][0];
        int v = requests[i][1];
        bool restricted = false;
        for (int j = 0; j < restrictionsSize; j++) {
            int r1 = restrictions[j][0];
            int r2 = restrictions[j][1];
            if ((find_set(u, parent) == find_set(r1, parent) && find_set(v, parent) == find_set(r2, parent)) ||
                (find_set(u, parent) == find_set(r2, parent) && find_set(v, parent) == find_set(r1, parent))) {
                restricted = true;
                break;
            }
        }
        result[i] = !restricted;
    }

    free(parent);
    return result;
}
