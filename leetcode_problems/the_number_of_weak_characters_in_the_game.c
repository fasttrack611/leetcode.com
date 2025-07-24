int numberOfWeakCharacters(int** properties, int propertiesSize, int* propertiesColSize) {
    qsort(properties, propertiesSize, sizeof(int*), [](const void* a, const void* b) {
        int* propA = *(int**)a;
        int* propB = *(int**)b;
        if (propA[0] != propB[0]) {
            return propB[0] - propA[0];
        } else {
            return propA[1] - propB[1];
        }
    });

    int weak_count = 0;
    int max_defense = 0;
    for (int i = 0; i < propertiesSize; i++) {
        if (properties[i][1] < max_defense) {
            weak_count++;
        } else {
            max_defense = properties[i][1];
        }
    }

    return weak_count;
}
