#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return result;
    }

    int first_critical = -1;
    int last_critical = -1;
    int min_dist = INT_MAX;
    int index = 1;
    struct ListNode* prev = head;
    struct ListNode* current = head->next;

    while (current->next != NULL) {
        if ((current->val > prev->val && current->val > current->next->val) ||
            (current->val < prev->val && current->val < current->next->val)) {
            if (first_critical == -1) {
                first_critical = index;
            } else {
                min_dist = (index - last_critical < min_dist) ? (index - last_critical) : min_dist;
            }
            last_critical = index;
        }
        prev = current;
        current = current->next;
        index++;
    }

    if (first_critical != -1 && first_critical != last_critical) {
        result[0] = min_dist;
        result[1] = last_critical - first_critical;
    }

    return result;
}
