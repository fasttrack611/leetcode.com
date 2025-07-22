#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int pairSum(struct ListNode* head) {
    int values[100000];
    int count = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        values[count++] = current->val;
        current = current->next;
    }

    int max_sum = 0;
    for (int i = 0; i < count / 2; i++) {
        int twin_sum = values[i] + values[count - 1 - i];
        if (twin_sum > max_sum) {
            max_sum = twin_sum;
        }
    }

    return max_sum;
}
