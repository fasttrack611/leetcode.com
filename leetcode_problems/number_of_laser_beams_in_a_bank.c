#include <stdio.h>
#include <string.h>

int numberOfBeams(char** bank, int bankSize) {
    int prev_devices = 0;
    int total_beams = 0;
    for (int i = 0; i < bankSize; i++) {
        int current_devices = 0;
        for (int j = 0; j < strlen(bank[i]); j++) {
            if (bank[i][j] == '1') {
                current_devices++;
            }
        }
        if (current_devices > 0) {
            total_beams += prev_devices * current_devices;
            prev_devices = current_devices;
        }
    }
    return total_beams;
}
