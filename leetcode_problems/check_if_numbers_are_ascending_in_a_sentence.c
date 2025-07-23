#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool areNumbersAscending(char * s){
    int last = -1;
    char *p = strtok(s, " ");
    while (p) {
        if (isdigit(p[0])) {
            int curr = atoi(p);
            if (curr <= last) {
                return false;
            }
            last = curr;
        }
        p = strtok(NULL, " ");
    }
    return true;
}

int main() {
    char s[] = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
    printf("Are numbers ascending: %s\n", areNumbersAscending(s) ? "true" : "false");
    return 0;
}
