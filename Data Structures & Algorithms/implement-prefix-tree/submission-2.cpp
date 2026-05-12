    struct TreeNode {
        unordered_map<char, TreeNode*> children;
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

        int idx = 0;
        while(idx < word.size()) {
            if (curr->children.count(word[idx])) {
                curr = curr->children[word[idx]];
                ++idx;
            } else {
                TreeNode* newNode = new TreeNode(word[idx]);
                curr->children[word[idx]] = newNode;
            }
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        if (!root) return false;

        TreeNode* curr = root;

        int idx = 0;
        while (true) {
            if (curr->children.count(word[idx])) {
                curr = curr->children[word[idx]];
                ++idx;
            } else return (idx == word.size() && curr && curr->isEnd);
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        if (!root) return false;

        TreeNode* curr = root;

        int idx = 0;
        while (true) {
            if (curr->children.count(prefix[idx])) {
                    curr = curr->children[prefix[idx]];
                    ++idx;
            }
            else return idx == prefix.size();
        }
        return false;
    }

private:
    TreeNode* root;

};
