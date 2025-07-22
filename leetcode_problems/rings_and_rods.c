#include <stdio.h>
#include <string.h>

int countPoints(char* rings) {
    int rods[10] = {0};
    int len = strlen(rings);
    for (int i = 0; i < len; i += 2) {
        int color = 0;
        if (rings[i] == 'R') {
            color = 1;
        } else if (rings[i] == 'G') {
            color = 2;
        } else {
            color = 4;
        }
        rods[rings[i + 1] - '0'] |= color;
    }

    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (rods[i] == 7) {
            count++;
        }
    }
    return count;
}
