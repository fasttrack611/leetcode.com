#include <stdio.h>
#include <stdlib.h>

int networkBecomesIdle(int** edges, int edgesSize, int* edgesColSize, int* patience, int patienceSize) {
    int* dist = (int*)malloc(sizeof(int) * patienceSize);
    for (int i = 0; i < patienceSize; i++) {
        dist[i] = -1;
    }
    dist[0] = 0;

    int** adj = (int**)malloc(sizeof(int*) * patienceSize);
    for (int i = 0; i < patienceSize; i++) {
        adj[i] = (int*)malloc(sizeof(int) * patienceSize);
    }
    int* adjCount = (int*)calloc(patienceSize, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        adj[edges[i][0]][adjCount[edges[i][0]]++] = edges[i][1];
        adj[edges[i][1]][adjCount[edges[i][1]]++] = edges[i][0];
    }

    int* queue = (int*)malloc(sizeof(int) * patienceSize);
    int head = 0, tail = 0;
    queue[tail++] = 0;

    while (head < tail) {
        int u = queue[head++];
        for (int i = 0; i < adjCount[u]; i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                queue[tail++] = v;
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i < patienceSize; i++) {
        int time = 2 * dist[i];
        int lastSend = (time - 1) / patience[i] * patience[i];
        maxTime = fmax(maxTime, lastSend + time);
    }

    free(dist);
    for (int i = 0; i < patienceSize; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjCount);
    free(queue);

    return maxTime + 1;
}

int main() {
    int edges[][2] = {{0,1},{1,2}};
    int edgesSize = sizeof(edges) / sizeof(edges[0]);
    int edgesColSize[] = {2, 2};
    int patience[] = {0,2,1};
    int patienceSize = sizeof(patience) / sizeof(patience[0]);

    int** edgesPtr = (int**)malloc(sizeof(int*) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        edgesPtr[i] = (int*)malloc(sizeof(int) * 2);
        edgesPtr[i][0] = edges[i][0];
        edgesPtr[i][1] = edges[i][1];
    }

    printf("Time when network becomes idle: %d\n", networkBecomesIdle(edgesPtr, edgesSize, edgesColSize, patience, patienceSize));

    for (int i = 0; i < edgesSize; i++) {
        free(edgesPtr[i]);
    }
    free(edgesPtr);

    return 0;
}
