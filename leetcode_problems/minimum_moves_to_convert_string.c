#include <stdio.h>
#include <string.h>

int minimumMoves(char * s){
    int moves = 0;
    int i = 0;
    while (i < strlen(s)) {
        if (s[i] == 'X') {
            moves++;
            i += 3;
        } else {
            i++;
        }
    }
    return moves;
}

int main() {
    char s[] = "XXX";
    printf("Minimum moves: %d\n", minimumMoves(s));
    return 0;
}
