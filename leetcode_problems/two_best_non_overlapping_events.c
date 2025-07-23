#include <stdio.h>
#include <stdlib.h>

int cmp_events(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    qsort(events, eventsSize, sizeof(int*), cmp_events);
    int max_val = 0;
    int max_so_far = 0;
    int j = 0;
    for (int i = 0; i < eventsSize; i++) {
        while (j < eventsSize && events[j][0] <= events[i][1]) {
            max_so_far = (events[j][2] > max_so_far) ? events[j][2] : max_so_far;
            j++;
        }
        int current_val = events[i][2];
        if (i > 0) {
           int prev_max = 0;
            for(int k=0; k < i; k++){
                if(events[k][1] < events[i][0]){
                    if(events[k][2] > prev_max){
                        prev_max = events[k][2];
                    }
                }
            }
            current_val += prev_max;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }
    }
    return max_val;
}
