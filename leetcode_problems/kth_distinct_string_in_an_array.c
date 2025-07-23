#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* kthDistinct(char** arr, int arrSize, int k) {
    for (int i = 0; i < arrSize; i++) {
        int count = 0;
        for (int j = 0; j < arrSize; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                count++;
            }
        }
        if (count == 1) {
            k--;
            if (k == 0) {
                return arr[i];
            }
        }
    }
    return "";
}
