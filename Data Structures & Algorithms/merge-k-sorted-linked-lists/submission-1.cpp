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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, Cmp> min_heap;
        for (auto node : lists)
            if (node) min_heap.push(node);

        ListNode dummy(0);
        ListNode *it = &dummy;

        while (!min_heap.empty()) {
            it->next = min_heap.top();
            it = it->next;

            min_heap.pop();
            if (it->next) min_heap.push(it->next);
        }
    
        return dummy.next;
    }
private:
    struct Cmp {
        bool operator()(const ListNode *a, const ListNode *b) const {
            return a->val > b->val;
        }
    };
};
