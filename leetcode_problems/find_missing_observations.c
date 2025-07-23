#include <stdio.h>
#include <stdlib.h>

int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    int m = rollsSize;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += rolls[i];
    }

    int n_sum = mean * (m + n) - sum;
    if (n_sum < n || n_sum > 6 * n) {
        *returnSize = 0;
        return NULL;
    }

    int* res = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    int avg = n_sum / n;
    int rem = n_sum % n;
    for (int i = 0; i < n; i++) {
        res[i] = avg + (i < rem);
    }

    return res;
}

int main() {
    int rolls[] = {3, 2, 4, 3};
    int mean = 4;
    int n = 2;
    int returnSize;
    int* res = missingRolls(rolls, 4, mean, n, &returnSize);
    if (returnSize > 0) {
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
        free(res);
    } else {
        printf("No solution\n");
    }
    return 0;
}
