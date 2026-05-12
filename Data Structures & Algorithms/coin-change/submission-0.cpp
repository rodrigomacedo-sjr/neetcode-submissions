class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            int min = INT_MAX, attempt;
            for (auto c : coins) {
                if (i - c >= 0 && dp[i - c] != -1) {
                    attempt = dp[i - c] + 1;
                    if (attempt < min)
                        min = attempt;
                }
                dp[i] = min != INT_MAX ? min : -1;
            }
        }
        return dp[amount];
    }
};
