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

        vector<ListNode*> nodes;
        ListNode *it = head;
        while (it != nullptr) {
            nodes.push_back(it);
            it = it->next;
        }
        for (int i = 0; i < nodes.size() / 2; i++) {
            nodes[i]->next = nodes[nodes.size() - 1 - i];

            nodes[nodes.size() - 1 - i]->next = nodes[i + 1];
        }
        nodes[nodes.size() / 2]->next = nullptr;
    }
};
