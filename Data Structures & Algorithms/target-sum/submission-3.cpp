class Solution {
private:
   vector<unordered_map<int, int>> dp;
    int dfs(vector<int>& nums, int idx, int target) {

        if (dp[idx].count(target) != 0) return dp[idx][target];

        if (idx >= nums.size()) {
            if (target == 0) return dp[idx][target] =1;
            else return dp[idx][target] = 0;
        }

        int total = 0;
        total += dfs(nums, idx + 1, target + nums[idx]);
        total += dfs(nums, idx + 1, target - nums[idx]);

        return dp[idx][target] = total;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.assign(nums.size() + 1, unordered_map<int, int>());
    
        return dfs(nums, 0, target);
    }
};
