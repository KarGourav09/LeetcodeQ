#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list node.
 */
#ifndef LISTNODE_H
#define LISTNODE_H
struct ListNode {
    int val;
    struct ListNode *next;
};
#endif

/**
 * addTwoNumbers - Add two numbers represented as linked lists
 * @l1: First linked list (digits in reverse order)
 * @l2: Second linked list (digits in reverse order)
 *
 * Return: Pointer to the head of the sum linked list
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    
    struct ListNode* current = dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        int digit = sum % 10;
        
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = digit;
        current->next->next = NULL;
        current = current->next;
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

/* Simple test harness */
int main(void) {
    /* l1: 2 -> 4 -> 3 */
    struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    /* l2: 5 -> 6 -> 4 */
    struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct ListNode *res = addTwoNumbers(l1, l2);

    /* Print result list */
    struct ListNode *p = res;
    while (p) {
        printf("%d", p->val);
        if (p->next) printf(" -> ");
        p = p->next;
    }
    printf("\n");

    /* free allocated nodes (simple cleanup) */
    while (res) {
        struct ListNode *tmp = res->next;
        free(res);
        res = tmp;
    }
    /* free l1 and l2 nodes created earlier (they were not reused by addTwoNumbers) */
    while (l1) {
        struct ListNode *tmp = l1->next;
        free(l1);
        l1 = tmp;
    }
    while (l2) {
        struct ListNode *tmp = l2->next;
        free(l2);
        l2 = tmp;
    }

    return 0;
}