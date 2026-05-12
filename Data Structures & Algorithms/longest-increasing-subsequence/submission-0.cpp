class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, 0, -1, 0);
    }
private:
    int helper(vector<int>& nums, int len, int front, int idx) {
        if (idx >= nums.size()) return len;

        int attempt1 = 0, attempt2;
        if (front == -1 || nums[idx] > nums[front])
            attempt1 = helper(nums, len + 1, idx, idx + 1);
        
        attempt2 = helper(nums, len, front, idx + 1);

        return max(attempt1, attempt2);
    }
};
/*
len
front
idx

int func(len, front, idx)
    if out of bounds return 0

if i can add idx to front
    attempt = func(len + 1, idx, idx + 1)

attempt2 = func(len, front, idx + 1)

return max(attempt, attempt2) + 1

*/