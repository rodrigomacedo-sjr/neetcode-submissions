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

    string encode(int a, int b) {
        return to_string(a) + " " + to_string(b);
    }

    void check(vector<vector<char>>& board, string word, int row, int col, int idx) {
        if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0) return;

        if (word[idx] != board[row][col] || found) return;

        if (used[encode(row, col)]) return;

        if (word[idx] == board[row][col]) {
            if (idx + 1 >= word.size()) { found = true; return; }
            used[encode(row, col)] = true;

            check(board, word, row, col + 1, idx + 1);
            check(board, word, row, col - 1, idx + 1);
            check(board, word, row + 1, col, idx + 1);
            check(board, word, row - 1, col, idx + 1);

            used[encode(row, col)] = false;
        }
    }
};
