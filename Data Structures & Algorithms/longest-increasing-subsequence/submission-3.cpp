class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLis = 1, n = nums.size();

        memo.assign(n, -1);
        
        for (int i = 0; i < n; ++i)
            maxLis = max(maxLis, dfs(nums, i));

        return maxLis;
    }
private:
    vector<int> memo;

    int dfs(vector<int>& nums, int idx) {
        if (memo[idx] != -1) return memo[idx];

        int LIS = 1;

        for (int i = idx + 1; i < nums.size(); ++i) {
            if (nums[i] > nums[idx])
                LIS = max(LIS, dfs(nums, i) + 1);
        }

        memo[idx] = LIS;
        return LIS;
    }
};