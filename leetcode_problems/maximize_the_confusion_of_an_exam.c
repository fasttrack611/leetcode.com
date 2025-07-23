#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxConsecutiveAnswers(char * answerKey, int k){
    int n = strlen(answerKey);
    int left = 0, right = 0;
    int t_count = 0, f_count = 0;
    int ans = 0;
    while (right < n) {
        if (answerKey[right] == 'T') {
            t_count++;
        } else {
            f_count++;
        }
        while (t_count > k && f_count > k) {
            if (answerKey[left] == 'T') {
                t_count--;
            } else {
                f_count--;
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main() {
    char answerKey[] = "TTFF";
    int k = 2;
    printf("Max consecutive answers: %d\n", maxConsecutiveAnswers(answerKey, k));
    return 0;
}
