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
        ListNode *cur = head, *prev = nullptr, *temp, *last, *remove, *sub;

        while (cur != nullptr) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        last = prev;

        temp = last;
        for (int i = 1; i < n; ++i) {
            temp = temp->next;
        }
        remove = temp;
        sub = remove->next;

        cur = last;
        prev = nullptr;
        while (cur != nullptr) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        if (remove == head) return head->next;

        sub->next = remove->next;
        return head;
    }
};
