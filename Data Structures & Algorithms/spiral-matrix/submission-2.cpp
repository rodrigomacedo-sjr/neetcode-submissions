class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        vector<int> ans;

        int row = 0, col = 0, size = rows * cols;

        int mod = 0, processed = 1;

        while (true) {
            for (int i = 0; i < cols - max(mod, 1); ++i) {
                ans.push_back(matrix[row][col++]);
                processed++;
            }

            if (processed >= size) break;
            mod++;

            for (int i = 0; i < rows - mod; ++i) {
                ans.push_back(matrix[row++][col]);
                processed++;
            }

            if (processed >= size) break;

            for (int i = 0; i < cols - mod; ++i) {
                ans.push_back(matrix[row][col--]);
                processed++;
            }

            if (processed >= size) break;
            mod++;

            for (int i = 0; i < rows - mod; ++i) {
                ans.push_back(matrix[row--][col]);
                processed++;
            }

            if (processed >= size) break;
        }
        ans.push_back(matrix[row][col]);

        return ans;
    }
};
