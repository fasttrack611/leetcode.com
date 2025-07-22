#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool checkValid(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    for (int i = 0; i < n; i++) {
        bool* row_check = (bool*)calloc(n + 1, sizeof(bool));
        bool* col_check = (bool*)calloc(n + 1, sizeof(bool));
        for (int j = 0; j < n; j++) {
            if (row_check[matrix[i][j]] || col_check[matrix[j][i]]) {
                free(row_check);
                free(col_check);
                return false;
            }
            row_check[matrix[i][j]] = true;
            col_check[matrix[j][i]] = true;
        }
        free(row_check);
        free(col_check);
    }
    return true;
}
