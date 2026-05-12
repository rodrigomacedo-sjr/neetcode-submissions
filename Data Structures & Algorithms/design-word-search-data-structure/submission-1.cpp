struct TreeNode {
    bool isFinal;
    vector<TreeNode*> children;

    TreeNode() : isFinal(false), children(vector<TreeNode*>(26, nullptr)) {}
};

class WordDictionary {

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

    bool search(string word) {
        return private_search(word, root);
    }

private:
    TreeNode* root;

    bool private_search(const string& word, TreeNode *start, int idx = 0) {
        TreeNode* curr = start;

        for (int i = idx; i < word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (auto child : curr->children) {
                    if (child && private_search(word, child, i + 1)) return true;
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
