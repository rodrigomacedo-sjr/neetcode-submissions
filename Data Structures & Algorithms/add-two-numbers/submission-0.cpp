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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
            if (a list is over, treat it as zero)
            r->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            if we end the process and still have a carry, create a new node in R
        */

        ListNode *ans = nullptr, *it = nullptr;
        int carry = 0;
        while (l1 || l2 || carry != 0) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;

            if (ans) {
                it->next = new ListNode(sum);
                it = it->next;
            }
            else {
                ans = new ListNode(sum);
                it = ans;
            }
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return ans;
    }
};
