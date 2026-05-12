class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (found) break;
                else check(board, word, i, j, 0);
        return found;
    }

private:
    unordered_map<string, bool> used;

    bool found = false;

    void check(vector<vector<char>>& board, string word, int x, int y, int idx) {
        if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0) return;

        if (word[idx] != board[x][y] || found) return;

        if (used[to_string(x) + " " + to_string(y)]) return;

        if (word[idx] == board[x][y]) {
            if (idx + 1 >= word.size()) { found = true; return; }
            used[to_string(x) + " " + to_string(y)] = true;

            check(board, word, x, y + 1, idx + 1);
            check(board, word, x, y - 1, idx + 1);
            check(board, word, x + 1, y, idx + 1);
            check(board, word, x - 1, y, idx + 1);

            used[to_string(x) + " " + to_string(y)] = false;
        }
    }
};
