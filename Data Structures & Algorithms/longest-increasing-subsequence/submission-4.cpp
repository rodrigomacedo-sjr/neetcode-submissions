class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLIS = 1, n = nums.size();

        vector<int> memo(n, -1);
        
        for (int i = n - 1; i >= 0; --i) {
            int lis = 1;
            for (int j = i + 1; j < n; ++j)
                if (nums[j] > nums[i])
                    lis = max(lis, memo[j] + 1);
            memo[i] = lis;
            maxLIS = max(lis, maxLIS);
        }
        return maxLIS;
    }
};