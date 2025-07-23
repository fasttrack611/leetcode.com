#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool winnerOfGame(char * colors){
    int alice = 0;
    int bob = 0;
    for (int i = 1; i < strlen(colors) - 1; i++) {
        if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
            if (colors[i] == 'A') {
                alice++;
            } else {
                bob++;
            }
        }
    }
    return alice > bob;
}

int main() {
    char colors[] = "AAABABB";
    printf("Alice wins: %s\n", winnerOfGame(colors) ? "true" : "false");
    return 0;
}
