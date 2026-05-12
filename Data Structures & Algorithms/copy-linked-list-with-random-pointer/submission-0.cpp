/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        vector<Node*> oldList, newList;
        unordered_map<Node*, int> idxs;
        Node *it = head;

        int idx = 0;
        while (it != nullptr) {
            oldList.push_back(it);
            idxs[it] = idx++;
            it = it->next;
        }
        int sz = idx;

        for (int i = 0; i < sz; ++i) {
            Node *newNode = new Node(oldList[i]->val);
            newList.push_back(newNode);
        }

        for (int i = 0; i < sz; ++i) {
            newList[i]->next = i + 1 < sz ? newList[i + 1] : nullptr;
            if (oldList[i]->random != nullptr)
                newList[i]->random = newList[idxs[oldList[i]->random]];
        }

        return newList[0];
    }
};
