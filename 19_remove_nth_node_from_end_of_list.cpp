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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        std::vector<ListNode*> vec;
        while (node) {
            vec.push_back(node);
            node = node->next;   
        }
        int index = vec.size() - n;
        if (index == 0) {
            if (vec.size() == 1)
                return 0;
            return vec[1];    
        }
        
        vec[index-1]->next = (index+1 < vec.size()? vec[index +1]: 0);
        
        return head;
    }
};

