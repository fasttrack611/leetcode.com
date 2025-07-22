#include <stdio.h>
#include <string.h>

int minimumBuckets(char* street) {
    int len = strlen(street);
    int buckets = 0;
    for (int i = 0; i < len; i++) {
        if (street[i] == 'H') {
            if (i > 0 && street[i - 1] == 'B') {
                continue;
            }
            if (i < len - 1 && street[i + 1] == '.') {
                street[i + 1] = 'B';
                buckets++;
            } else if (i > 0 && street[i - 1] == '.') {
                street[i - 1] = 'B';
                buckets++;
            } else {
                return -1;
            }
        }
    }
    return buckets;
}
