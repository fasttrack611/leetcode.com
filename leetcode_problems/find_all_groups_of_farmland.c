int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * landSize * (*landColSize));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * landSize * (*landColSize));

    for (int i = 0; i < landSize; i++) {
        for (int j = 0; j < *landColSize; j++) {
            if (land[i][j] == 1) {
                int r1 = i;
                int c1 = j;
                int r2 = i;
                int c2 = j;
                while (r2 + 1 < landSize && land[r2 + 1][j] == 1) {
                    r2++;
                }
                while (c2 + 1 < *landColSize && land[i][c2 + 1] == 1) {
                    c2++;
                }

                result[*returnSize] = (int*)malloc(sizeof(int) * 4);
                result[*returnSize][0] = r1;
                result[*returnSize][1] = c1;
                result[*returnSize][2] = r2;
                result[*returnSize][3] = c2;
                (*returnColumnSizes)[*returnSize] = 4;
                (*returnSize)++;

                for (int row = r1; row <= r2; row++) {
                    for (int col = c1; col <= c2; col++) {
                        land[row][col] = 0;
                    }
                }
            }
        }
    }

    return result;
}
