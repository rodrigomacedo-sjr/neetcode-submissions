class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, m = (r - l + 1) / 2;

        while (l != r) {
            if (nums[l] > nums[r]) {
                if (nums[m] < nums[r]) r = m;
                else if (nums[m] > nums[r]) l = m;

                m = (r - l + 1) / 2 + l;
            }
            
            if (nums[l] < nums[r] || nums[l] == nums[m] || nums[r] == nums[m])
                return min(nums[l], nums[r]);
        }
        return nums[l];
    }
};
