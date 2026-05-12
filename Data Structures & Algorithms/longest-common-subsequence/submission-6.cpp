class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size())
            swap(text1, text2);

        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(2, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (text1[i] == text2[j])
                    dp[0][j] = 1 + dp[1][j + 1];
                else
                    dp[0][j] = max(dp[1][j], dp[0][j + 1]);
            }
            for (int j = m - 1; j >= 0; --j)                
                dp[1][j] = dp[0][j];
        }

        return dp[0][0];
    }
};
