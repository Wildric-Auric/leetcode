#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* n = head;
        if (!head || !n->next)
            return n;
        ListNode* a = 0;
        ListNode* b = 0;
        ListNode* c = 0;
        head = n->next;
        while (n && n->next) {
            b = n;
            c = n->next;

            b->next = n->next->next;
            c->next = b;

            if (a)
                a->next = c;
            n = b->next;
            a = b;
        }
        return head;
    }
};