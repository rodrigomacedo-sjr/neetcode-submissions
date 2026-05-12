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
        cout << "inserting: " << word << "\n\n";
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

        TreeNode* curr = root, *prev = nullptr;
        int idx = 0;
        cout << "searching "<< word << " : \n";
        while (true) {
            bool found = false;
            for (auto child : curr->children) {
                if (child->val == word[idx]) {
                    cout << child->val << "\n";
                    prev = curr;
                    curr = child;
                    ++idx;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "done searching (true)\n";
                cout << "idx: " << idx << "\n";
                cout << "word.size(): " << word.size() << "\n";
                cout << "!!prev: " << !!prev << "\n";
                if (prev) cout << "prev->isEnd: " << prev->isEnd << "\n\n";
                return (idx == word.size() && curr && curr->isEnd);
            }

        }
        cout << "done searching\n\n";
        cout << "idx: " << idx << "\n";
        cout << "word.size(): " << word.size() << "\n";
        cout << "!!prev: " << !!prev << "\n";
        if (prev) cout << "prev->isEnd: " << prev->isEnd << "\n\n";
        return false;
    }
    
    bool startsWith(string prefix) {
        if (!root) return false;

        TreeNode* curr = root;
        int idx = 0;

cout << "startsWith "<< prefix << " : \n";
        
        while (true) {
            bool found = false;
            for (auto child : curr->children) {
                if (child->val == prefix[idx]) {
                    cout << child->val << "\n";
                    curr = child;
                    ++idx;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "done prefixing (true)\n\n";
                cout << "idx: " << idx << "\n";
                cout << "prefix.size(): " << prefix.size() << "\n";
                return idx == prefix.size();
            }
        }
        cout << "done prefixing\n\n";
        cout << "idx: " << idx << "\n";
        cout << "prefix.size(): " << prefix.size() << "\n";
        return false;
    }

private:
    TreeNode* root;

};
