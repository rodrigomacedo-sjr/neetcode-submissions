class Solution {
private:
    int total = 0;

    int dfs(vector<int>& nums, int target, int idx) {
        if (idx >= nums.size()) {
            if (target == 0) return 1;
            return 0;
        }

        int total = 0;
        total += dfs(nums, target + nums[idx], idx + 1);
        total += dfs(nums, target - nums[idx], idx + 1);

        return total;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }
};
