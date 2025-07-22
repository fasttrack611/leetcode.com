#include <stdio.h>
#include <stdlib.h>

int minimumRounds(int* tasks, int tasksSize) {
    qsort(tasks, tasksSize, sizeof(int), cmpfunc);
    int rounds = 0;
    int i = 0;
    while (i < tasksSize) {
        int j = i;
        while (j < tasksSize && tasks[j] == tasks[i]) {
            j++;
        }
        int count = j - i;
        if (count == 1) {
            return -1;
        }
        rounds += (count + 2) / 3;
        i = j;
    }
    return rounds;
}

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
