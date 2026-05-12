class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRowZero = false;
    
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        firstRowZero = true;
                    else
                        matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for (int i = n - 1; i >= 1; --i)
            for (int j = m - 1; j >= 0; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

        if (firstRowZero)
            for (int j = 0; j < m; ++j)
                matrix[0][j] = 0;
    }
};
