class Solution {
private:
    unordered_map<int, int> memo;

    int dfs(vector<int>& cost, int idx) {
        if (memo.count(idx)) return memo[idx];

        if (idx >= cost.size()) {
            return 0;
        }

        int best = INT_MAX;
        for (int i = 1; i <= 2; ++i) {
            int attempt = cost[idx] + dfs(cost, idx + i);
            best = min(attempt, best);
        }

        return memo[idx] = best;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(cost, 0), dfs(cost, 1));
    }
};
