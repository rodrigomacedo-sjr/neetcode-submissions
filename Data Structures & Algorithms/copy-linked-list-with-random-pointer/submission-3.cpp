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
    // O(1) space
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        /*
        A -> B
        A -> A' -> B
        */
        Node *it = head, *prev = nullptr;
        while (it != nullptr) {
            Node *copy = new Node(it->val);
            copy->next = it->next;
            it->next = copy;
            it = copy->next;
        }

        /*
        A'(random) = A(random)->next
        */
        it = head->next;
        prev = head;
        while (it != nullptr) {
            it->random = prev->random ? prev->random->next : nullptr;

            if (it->next) {
                it = it->next->next;
                prev = prev->next->next;
            } else break;
        }

        /*
        A -> A' -> B -> B'
        A' -> B'
        A -> B
        */
        Node *copiedList = head->next, *copyIt = copiedList;
        it = head;

        while (copyIt->next != nullptr) {
            it->next = copyIt->next;
            copyIt->next = copyIt->next->next;

            it = it->next;
            copyIt = copyIt->next;
        }
        it->next = nullptr;

        return copiedList;
    }
};
