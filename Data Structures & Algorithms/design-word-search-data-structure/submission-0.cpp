struct TreeNode {
    bool isFinal;
    vector<TreeNode*> children;

    TreeNode() : isFinal(false), children(vector<TreeNode*>(26, nullptr)) {}
};

class WordDictionary {
private:
    TreeNode* root;
public:
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                TreeNode* newNode = new TreeNode();
                curr->children[c - 'a'] = newNode;
            }
            curr = curr->children[c - 'a'];
        }
        curr->isFinal = true;
    }
    
    bool search(string word, TreeNode *start = nullptr, int idx = 0) {
        TreeNode* curr = start ? start : root;

        for (int i = idx; i < word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (auto child : curr->children) {
                    if (child && search(word, child, i + 1)) return true;
                }
                return false;
            }
            else if (curr->children[c - 'a']) {
                curr = curr->children[c - 'a'];
            } else {
                curr = nullptr;
                break;
            }
        }

        return curr && curr->isFinal;
    }
};
