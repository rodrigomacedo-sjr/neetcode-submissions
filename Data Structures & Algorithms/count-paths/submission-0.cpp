class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        
        for (int i = 1; i < m; ++i) {
            int prev = 1;
            for (int j = 1; j < n; ++j) {
                dp[j] = dp[j] + prev;
                prev = dp[j];
            }
        }

        return dp[n - 1];
    }
};
