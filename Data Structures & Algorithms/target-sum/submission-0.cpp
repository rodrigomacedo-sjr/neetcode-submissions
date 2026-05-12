class Solution {
private:
    int total = 0;

    void dfs(vector<int>& nums, int target, int idx) {
        if (idx >= nums.size()) {
            if (target == 0) total++;
            return;
        }

        dfs(nums, target + nums[idx], idx + 1);
        dfs(nums, target - nums[idx], idx + 1);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0);
    
        return total;
    }
};
