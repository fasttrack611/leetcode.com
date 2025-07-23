#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int m = gridSize;
    int n = *gridColSize;
    int* arr = (int*)malloc(sizeof(int) * m * n);
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = grid[i][j];
        }
    }

    qsort(arr, m * n, sizeof(int), compare);
    int median = arr[(m * n) / 2];
    int ans = 0;
    for (int i = 0; i < m * n; i++) {
        if (abs(arr[i] - median) % x != 0) {
            return -1;
        }
        ans += abs(arr[i] - median) / x;
    }

    free(arr);
    return ans;
}

int main() {
    int grid_data[][3] = {{2, 4, 16}, {2, 2, 2}};
    int* grid[2];
    grid[0] = grid_data[0];
    grid[1] = grid_data[1];
    int gridSize = 2;
    int gridColSize[] = {3, 3};
    int x = 2;

    printf("Minimum operations: %d\n", minOperations(grid, gridSize, gridColSize, x));

    return 0;
}
