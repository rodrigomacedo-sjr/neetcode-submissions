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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *p = nullptr, *c = head, *n = head->next;
        while (c != nullptr) {
            c->next = p;
            p = c;
            c = n;
            if (c != nullptr) n = c->next;
        }
        return p;
    }
};
