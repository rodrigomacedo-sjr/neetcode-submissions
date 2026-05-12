/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> clone;

    void bfs(Node* root) {
        if (!root) return;

        queue<Node*> qu;
        qu.push(root);

        clone[root] = new Node(root->val);

        while (!qu.empty()) {
            Node* curr = qu.front();
            qu.pop();

            for (auto n : curr->neighbors) {
                if (clone.count(n) == 0) {
                    clone[n] = new Node(n->val);
                    qu.push(n);
                }
                clone[curr]->neighbors.push_back(clone[n]); 
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        bfs(node);
        return clone[node];
    }
};
