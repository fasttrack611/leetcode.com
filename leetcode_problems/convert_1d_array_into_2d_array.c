#include <stdio.h>
#include <stdlib.h>

int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes){
    if (originalSize != m * n) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            result[i][j] = original[i * n + j];
        }
    }

    return result;
}

int main() {
    int original[] = {1, 2, 3, 4};
    int m = 2, n = 2;
    int returnSize;
    int* returnColumnSizes;
    int** result = construct2DArray(original, 4, m, n, &returnSize, &returnColumnSizes);
    if (returnSize > 0) {
        for (int i = 0; i < returnSize; i++) {
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
            free(result[i]);
        }
        free(result);
        free(returnColumnSizes);
    } else {
        printf("Cannot construct 2D array\n");
    }
    return 0;
}
