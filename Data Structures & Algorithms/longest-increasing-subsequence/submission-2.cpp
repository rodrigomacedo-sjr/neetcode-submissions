class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        memo.assign(nums.size() + 1, vector<int>(nums.size(), -1));
        return helper(nums, -1, 0);
    }
private:
    // front, idx
    vector<vector<int>> memo;

    int helper(vector<int>& nums, int front, int idx) {
        if (idx >= nums.size()) return 0;

        if (memo[front + 1][idx] != -1) return memo[front + 1][idx];

        int attempt1 = 0, attempt2;
        if (front == -1 || nums[idx] > nums[front])
            attempt1 = helper(nums, idx, idx + 1) + 1;
        
        attempt2 = helper(nums, front, idx + 1);
            
        memo[front + 1][idx] = max(attempt1, attempt2);
    
        return memo[front + 1][idx];
    }
};