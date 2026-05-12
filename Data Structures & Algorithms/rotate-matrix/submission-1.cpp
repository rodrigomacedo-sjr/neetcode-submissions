class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        while (top < bottom && left < right) {
            int prev, temp;
            int steps = right - left; 

            for (int k = 0; k < steps; ++k) {
                prev = matrix[top + 1][left];
                for (int i = left; i < right; ++i) {
                    temp = prev;
                    prev = matrix[top][i];
                    matrix[top][i] = temp;
                }

                for (int i = top; i < bottom; ++i) {
                    temp = prev;
                    prev = matrix[i][right];
                    matrix[i][right] = temp;   
                }

                for (int i = right; i > left; --i) {
                    temp = prev;
                    prev = matrix[bottom][i];
                    matrix[bottom][i] = temp;
                }

                for (int i = bottom; i > top; --i) {
                    temp = prev;
                    prev = matrix[i][left];
                    matrix[i][left] = temp;
                }
            }

            top++;
            bottom--;
            left++;
            right--;
        }
    }
};
