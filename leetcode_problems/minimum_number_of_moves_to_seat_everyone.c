#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize){
    qsort(seats, seatsSize, sizeof(int), compare);
    qsort(students, studentsSize, sizeof(int), compare);
    int moves = 0;
    for (int i = 0; i < seatsSize; i++) {
        moves += abs(seats[i] - students[i]);
    }
    return moves;
}

int main() {
    int seats[] = {3,1,5};
    int students[] = {2,7,4};
    int seatsSize = sizeof(seats) / sizeof(seats[0]);
    int studentsSize = sizeof(students) / sizeof(students[0]);
    printf("Minimum moves: %d\n", minMovesToSeat(seats, seatsSize, students, studentsSize));
    return 0;
}
