class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (check(board, word, i, j, 0)) return true;
        return false;
    }

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool check(vector<vector<char>>& board, const string& word, int row, int col, int idx) {
        if (row >= board.size() ||
            row < 0 ||
            col >= board[0].size() ||
            col < 0 ||
            word[idx] != board[row][col]) 
            return false;

        if (idx + 1 >= word.size()) return true;

        char temp = board[row][col];
        board[row][col] = '#';

        for (auto& d : dirs)
            if (check(board, word, row + d[0], col + d[1], idx + 1)) return true;

        board[row][col] = temp;

        return false;
    }
};
