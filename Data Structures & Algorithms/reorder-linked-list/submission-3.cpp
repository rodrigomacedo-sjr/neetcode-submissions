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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode *fast = head, *slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *middle = slow->next, *tail = nullptr, *temp;

        slow->next = nullptr;

        while (middle != nullptr) {
            temp = middle->next;
            middle->next = tail;
            tail = middle;
            middle = temp;
        }

        ListNode *l1 = head, *l2 = tail;

        while (l1 != nullptr && l2 != nullptr) {
            temp = l2;
            l2 = l2->next;
            temp->next = l1->next;
            l1->next = temp;
            l1 = temp->next;
        }

        if (l1 == nullptr && l2 != nullptr) temp->next = l2;
    }
};
