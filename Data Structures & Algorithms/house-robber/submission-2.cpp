class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);

        int prev = nums[0];
        int curr = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            int temp = curr;
            curr = max(nums[i] + prev, curr);
            prev = temp;
        }

        return curr;
    }
};
