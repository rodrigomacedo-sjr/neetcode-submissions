struct TreeNode {
    unordered_map<char, TreeNode*> children;
    bool isEnd;

    TreeNode() : children({}), isEnd(false) {}
};

class PrefixTree {
public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* curr = root;

        int idx = 0;
        while(idx < word.size()) {
            if (curr->children.count(word[idx])) {
                curr = curr->children[word[idx]];
                ++idx;
            } else {
                TreeNode* newNode = new TreeNode();
                curr->children[word[idx]] = newNode;
            }
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        if (!root) return false;

        TreeNode* curr = root;

        int idx = 0;
        while (idx < word.size()) {
            if (curr->children.count(word[idx])) {
                curr = curr->children[word[idx]];
                ++idx;
            } else break;
            if (idx == word.size() && curr && curr->isEnd) return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        if (!root) return false;

        TreeNode* curr = root;

        int idx = 0;
        while (idx < prefix.size()) {
            if (curr->children.count(prefix[idx])) {
                    curr = curr->children[prefix[idx]];
                    ++idx;
            } else break;
            if (idx == prefix.size()) return true;
        }
        return false;
    }

private:
    TreeNode* root;

};
