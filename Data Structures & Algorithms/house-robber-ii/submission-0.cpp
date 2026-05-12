class Solution {
private:
    int robAux(vector<int>& nums, int start, int end) {
        int prev = 0;
        int curr = 0;

        for (int i = start; i < end; ++i) {
            int temp = curr;
            curr = max(nums[i] + prev, curr);
            prev = temp;
        }

        return curr;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return max(robAux(nums, 0, nums.size() - 1), robAux(nums, 1, nums.size()));
    }
};
