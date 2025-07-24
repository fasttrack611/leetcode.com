bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    if (source == destination) {
        return true;
    }

    int* parent = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int root1 = find(parent, edges[i][0]);
        int root2 = find(parent, edges[i][1]);
        if (root1 != root2) {
            parent[root1] = root2;
        }
    }

    bool result = (find(parent, source) == find(parent, destination));
    free(parent);
    return result;
}

int find(int* parent, int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent, parent[i]);
}
