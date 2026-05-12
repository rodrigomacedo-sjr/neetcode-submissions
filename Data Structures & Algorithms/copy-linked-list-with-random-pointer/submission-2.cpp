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
        unordered_map<Node*, Node*> eq;
        Node *it = head;

        while (it != nullptr) {
            eq[it] = new Node(it->val);
            it = it->next;
        }

        for (auto kv : eq) {
            if (kv.first->next)
                eq[kv.first]->next = eq[kv.first->next];
            if (kv.first->random)
            eq[kv.first]->random = eq[kv.first->random];
        }
        
        return eq[head];
    }
};
