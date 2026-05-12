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

    pair<bool, bool> findWord(string word) {
        if (!root) return {false, false};

        TreeNode* curr = root;

        int idx = 0;
        while (idx < word.size()) {
            if (curr->children.count(word[idx])) {
                curr = curr->children[word[idx]];
                ++idx;
            } else break;
            if (idx == word.size() && curr->isEnd) return {true, true};
            else if (idx == word.size()) return {true, false};
        }
        return {false, false};   
    }
    
    bool search(string word) {
        auto [found, isEnd] = findWord(word);
        return found && isEnd;
    }
    
    bool startsWith(string prefix) {
        auto [found, isEnd] = findWord(prefix);
        return found;
    }

private:
    TreeNode* root;

};
