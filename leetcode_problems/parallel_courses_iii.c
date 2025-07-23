#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int minimumTime(int n, int** relations, int relationsSize, int* relationsColSize, int* time, int timeSize) {
    int* in_degree = (int*)calloc(n + 1, sizeof(int));
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 0; i < relationsSize; i++) {
        int u = relations[i][0];
        int v = relations[i][1];
        adj[u][v] = 1;
        in_degree[v]++;
    }

    int* queue = (int*)malloc(n * sizeof(int));
    int head = 0, tail = 0;
    int* dist = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            queue[tail++] = i;
            dist[i] = time[i - 1];
        }
    }

    while (head < tail) {
        int u = queue[head++];
        for (int v = 1; v <= n; v++) {
            if (adj[u][v]) {
                dist[v] = max(dist[v], dist[u] + time[v - 1]);
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[tail++] = v;
                }
            }
        }
    }

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max_time) {
            max_time = dist[i];
        }
    }

    free(in_degree);
    for (int i = 0; i <= n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(queue);
    free(dist);

    return max_time;
}
