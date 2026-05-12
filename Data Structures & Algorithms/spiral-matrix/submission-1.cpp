class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        vector<int> ans;

        int row = 0, col = 0;

        int mod = 0, processed = 0;

        while (true) {
            for (int i = 0; i < cols - max(mod, 1); ++i) {
                cout << "0row, col: " << row << ", " << col << ": " << matrix[row][col] << "\n";
                ans.push_back(matrix[row][col]);
                col++;
                processed++;
            }

            if (processed >= rows * cols - 1) break;
            mod++;

            for (int i = 0; i < rows - mod; ++i) {
                cout << "1row, col: " << row << ", " << col << ": " << matrix[row][col] << "\n";
                ans.push_back(matrix[row][col]);
                row++;
                processed++;
            }

            if (processed >= rows * cols- 1) break;

            for (int i = 0; i < cols - mod; ++i) {
                cout << "2row, col: " << row << ", " << col << ": " << matrix[row][col] << "\n";
                ans.push_back(matrix[row][col]);
                col--;
                processed++;
            }

            if (processed >= rows * cols - 1) break;
            mod++;

            for (int i = 0; i < rows - mod; ++i) {
                cout << "3row, col: " << row << ", " << col << ": " << matrix[row][col] << "\n";
                ans.push_back(matrix[row][col]);
                row--;
                processed++;
            }

            if (processed >= rows * cols - 1) break;
        }
        ans.push_back(matrix[row][col]);

        return ans;
    }
};
