struct TreeNode {
    vector<TreeNode*> children;
    bool isEnd;

    TreeNode() : children(vector<TreeNode*>(26, nullptr)), isEnd(false) {}
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
            if (!curr->children[word[idx] - 'a']) {
                TreeNode* newNode = new TreeNode();
                curr->children[word[idx] - 'a'] = newNode;
            }
            curr = curr->children[word[idx] - 'a'];
            ++idx;
        }
        curr->isEnd = true;
    }

    TreeNode* findWord(string word) {
        if (!root) return nullptr;

        TreeNode* curr = root;

        int idx = 0;
        while (idx < word.size()) {
            if (curr->children[word[idx] - 'a']) {
                curr = curr->children[word[idx] - 'a'];
                ++idx;
            } else break;
            if (idx == word.size()) return curr;
        }
        return nullptr;   
    }
    
    bool search(string word) {
        TreeNode* final = findWord(word);
        return (final && final->isEnd);
    }
    
    bool startsWith(string prefix) {
        TreeNode* final = findWord(prefix);
        return  final != nullptr;
    }

private:
    TreeNode* root;

};
