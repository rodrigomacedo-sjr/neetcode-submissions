class Solution {
private:
    int rows, cols;

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] == 'X' || board[row][col] == 'S') return;

        board[row][col] = 'S';

        for (auto d : dirs) {
            int rowN = row + d[0], colN = col + d[1];
            if (rowN < 0 || rowN >= rows || colN < 0 || colN >= cols)
                continue;
            dfs(board, rowN, colN);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }

        for (int j = 0; j < cols; ++j) {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
    }
};
