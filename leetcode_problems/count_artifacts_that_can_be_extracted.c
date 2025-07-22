#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int countArtifacts(int n, int** artifacts, int artifactsSize, int* artifactsColSize, int** dig, int digSize, int* digColSize) {
    bool** grid = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        grid[i] = (bool*)calloc(n, sizeof(bool));
    }

    for (int i = 0; i < digSize; i++) {
        grid[dig[i][0]][dig[i][1]] = true;
    }

    int count = 0;
    for (int i = 0; i < artifactsSize; i++) {
        bool can_extract = true;
        for (int r = artifacts[i][0]; r <= artifacts[i][2]; r++) {
            for (int c = artifacts[i][1]; c <= artifacts[i][3]; c++) {
                if (!grid[r][c]) {
                    can_extract = false;
                    break;
                }
            }
            if (!can_extract) {
                break;
            }
        }
        if (can_extract) {
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return count;
}
