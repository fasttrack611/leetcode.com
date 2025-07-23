#include <stdio.h>
#include <string.h>

int numOfPairs(char ** nums, int numsSize, char * target){
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i == j) continue;
            char temp[101];
            strcpy(temp, nums[i]);
            strcat(temp, nums[j]);
            if (strcmp(temp, target) == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char* nums[] = {"777","7","77","77"};
    char* target = "7777";
    printf("Number of pairs: %d\n", numOfPairs(nums, 4, target));
    return 0;
}
