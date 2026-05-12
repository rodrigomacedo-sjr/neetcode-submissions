class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            int attempt;
            for (auto c : coins) {
                if (i - c >= 0) {
                    attempt = dp[i - c] + 1;
                    dp[i] = min(attempt, dp[i]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
