struct TreeNode {
    TreeNode* children[26] = {nullptr};
    string* wordPtr = nullptr;
    int count = 0;
};

class Solution {
private:
    TreeNode* root;

    void addWord(string& word) {
        TreeNode* curr = root;

        for (char c : word) {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new TreeNode();
            curr->count++;
            curr = curr->children[c - 'a'];
        }
        curr->wordPtr = &word;
    }

    void removeWord(string& word) {
        TreeNode* curr = root;

        for (char c : word) {
            curr->count--;
            curr = curr->children[c - 'a'];
        }
        curr->wordPtr = nullptr;
    }

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<string> ans;

    void findHelper(TreeNode* node, vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#')
            return;

        if (node->count <= 0)
            return;

        TreeNode* nextNode = node->children[board[row][col] - 'a'];
        if (!nextNode)
            return;
        node = nextNode;

        if (node->wordPtr) {
            ans.push_back(*node->wordPtr);
            removeWord(*node->wordPtr);
        }

        char aux = board[row][col];
        board[row][col] = '#';

        for (auto d : dirs) {
            findHelper(node, board, row + d[0], col + d[1]);
        }

        board[row][col] = aux;
    }

public: 
    Solution() {
        root = new TreeNode();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
            addWord(words[i]);

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                findHelper(root, board, i, j);

        return ans;
    }
};
