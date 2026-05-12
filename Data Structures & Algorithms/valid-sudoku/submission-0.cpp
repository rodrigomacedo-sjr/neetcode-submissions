/*
fun
inicializar sets
col * setCol[i]
row * setRow[i]
9 * setSquare

itera por toda a matriz
    el = matriz[i][j]
    esta no setCol[j]?
    esta no setRow[i]?
    esta no setSq[i/3][j/3]?
        return false

    adiciona el nos sets

return true
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<set<int>> setCol(n);
        vector<set<int>> setRow(n);
        vector<vector<set<int>>> setSquare(3, vector<set<int>>(3));

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (board[row][col] == '.') continue;
                
                int curr = (int) board[row][col];

                if (setCol[col].count(curr) || setRow[row].count(curr) || setSquare[row / 3][col / 3].count(curr)) {
                    return false;
                }

                setCol[col].insert(curr);
                setRow[row].insert(curr);
                setSquare[row / 3][col / 3].insert(curr);
            }
        }

        return true;
    }
};
