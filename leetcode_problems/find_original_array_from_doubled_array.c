int* findOriginalArray(int* changed, int changedSize, int* returnSize) {
    if (changedSize % 2 != 0) {
        *returnSize = 0;
        return NULL;
    }

    int* counts = (int*)calloc(100001, sizeof(int));
    for (int i = 0; i < changedSize; i++) {
        counts[changed[i]]++;
    }

    int* original = (int*)malloc(sizeof(int) * (changedSize / 2));
    int original_idx = 0;

    for (int i = 0; i <= 100000; i++) {
        while (counts[i] > 0) {
            counts[i]--;
            if (i * 2 > 100000 || counts[i * 2] == 0) {
                *returnSize = 0;
                free(original);
                free(counts);
                return NULL;
            }
            counts[i * 2]--;
            original[original_idx++] = i;
        }
    }

    free(counts);
    *returnSize = changedSize / 2;
    return original;
}
