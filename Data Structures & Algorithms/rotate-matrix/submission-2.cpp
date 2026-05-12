class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        while (top < bottom && left < right) {
            int prev, temp;
            int steps = right - left; 

            for (int k = 0; k < steps; ++k) {
                // temp = top left
                temp = matrix[top][left + k];

                // top left = bottom left
                matrix[top][left + k] = matrix[bottom - k][left];   

                // bottom left = bottom right
                matrix[bottom - k][left] = matrix[bottom][right - k];

                // bottom right = top right
                matrix[bottom][right - k] = matrix[top + k][right];

                // top right = top left
                matrix[top + k][right] = temp;    
            }

            top++;
            bottom--;
            left++;
            right--;
        }
    }
};
