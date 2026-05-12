    struct TreeNode {
        vector<TreeNode*> children;
        bool isEnd;;
        char val;

        TreeNode() : children({}), isEnd(false), val('#') {}

        TreeNode(char c, bool e = false) : children({}), isEnd(e), val(c) {}
    };
class PrefixTree {
public:
    PrefixTree() {
        root = new TreeNode('#');
    }
    
    void insert(string word) {
        TreeNode* curr = root;

        bool found = false;

        int idx = 0;
        while(idx < word.size()) {
            for (auto child : curr->children) {
                if (child->val == word[idx]) {
                    curr = child;
                    found = true;
                    ++idx;
                    break;
                }
            }
            if (!found) {
                TreeNode* newNode = new TreeNode(word[idx]);
                curr->children.push_back(newNode);
            }
            found = false;
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        if (!root) return false;

        TreeNode* curr = root;
        int idx = 0;
        while (true) {
            bool found = false;
            for (auto child : curr->children) {
                if (child->val == word[idx]) {
                    curr = child;
                    ++idx;
                    found = true;
                    break;
                }
            }
            if (!found) return (idx == word.size() && curr && curr->isEnd);
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        if (!root) return false;

        TreeNode* curr = root;
        int idx = 0;
        
        while (true) {
            bool found = false;
            for (auto child : curr->children) {
                if (child->val == prefix[idx]) {
                    curr = child;
                    ++idx;
                    found = true;
                    break;
                }
            }
            if (!found) return idx == prefix.size();
        }
        return false;
    }

private:
    TreeNode* root;

};
