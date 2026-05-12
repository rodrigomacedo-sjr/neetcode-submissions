struct TreeNode {
    vector<TreeNode*> children;
    int wordIdx;

    TreeNode() : children(vector<TreeNode*>(26, nullptr)), wordIdx(-1) {}
};
class Solution {
private:
    TreeNode* root;

    void addWord(string& word, int idx) {
        TreeNode* curr = root;

        for (char c : word) {
            if (getChild(curr, c) == nullptr)
                addChild(curr, c);
            curr = getChild(curr, c);
        }
        curr->wordIdx = idx;
    } 

    TreeNode* getChild(TreeNode* node, char target) {
        return node->children[target - 'a'];
    }

    void addChild(TreeNode* node, char newC) {
        node->children[newC - 'a'] = new TreeNode();
    }

    vector<int> ansIdxs;

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void findHelper(TreeNode* node, vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#') 
            return;

        TreeNode* nextNode = getChild(node, board[row][col]);
        if (!nextNode)
            return;
        node = nextNode;

        if (node->wordIdx != -1) {
            ansIdxs.push_back(node->wordIdx);
            node->wordIdx = -1;
        }

        char aux = board[row][col];
        board[row][col] = '#';
        for (auto d : dirs) {
            int nextRow = row + d[0];
            int nextCol = col + d[1];
            if (nextRow < 0 || nextRow >= board.size() || nextCol < 0 || nextCol >= board[0].size() || board[nextRow][nextCol] == '#')
                continue;                 
            
            findHelper(node, board, nextRow, nextCol);
        }
        board[row][col] = aux;
    }
public: 
    
    Solution() {
        root = new TreeNode();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
            addWord(words[i], i);

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                findHelper(root, board, i, j);

        vector<string> ans;
        for (int i : ansIdxs)
            ans.push_back(words[i]);
        return ans;
    }
};
