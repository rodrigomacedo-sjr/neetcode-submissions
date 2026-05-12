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
        if (lists.size() == 0) return nullptr;
        ListNode *ans = nullptr, *removePointer, *it;
        int smallest, removeIdx;
        while (true) {
            smallest = INT_MAX;
            for (int i = 0; i < lists.size(); ++i) {
                if (!lists[i]) continue;
                else if (lists[i]->val < smallest) {
                    smallest = lists[i]->val;
                    removePointer = lists[i];
                    removeIdx = i;
                }
            }

            if (!ans) {
                ans = removePointer;
                lists[removeIdx] = removePointer->next;
                removePointer->next = nullptr;
                it = ans;
            } else {
                it->next = removePointer;
                lists[removeIdx] = removePointer->next;
                removePointer->next = nullptr;
                it = it->next;
            }

            if (smallest == INT_MAX) break;
        }
        return ans;
    }
};
