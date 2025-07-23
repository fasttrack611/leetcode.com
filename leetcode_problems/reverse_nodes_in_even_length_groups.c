#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* next_temp = current->next;
        current->next = prev;
        prev = current;
        current = next_temp;
    }
    return prev;
}

struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* prev = head;
    int group_len = 2;
    while (prev->next != NULL) {
        struct ListNode* group_start = prev->next;
        struct ListNode* group_end = group_start;
        int count = 1;
        while (count < group_len && group_end->next != NULL) {
            group_end = group_end->next;
            count++;
        }

        if (count % 2 == 0) {
            struct ListNode* next_group_start = group_end->next;
            group_end->next = NULL;
            prev->next = reverse(group_start);
            group_start->next = next_group_start;
            prev = group_start;
        } else {
            prev = group_end;
        }
        group_len++;
    }

    return head;
}
