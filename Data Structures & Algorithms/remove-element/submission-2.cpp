class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int r = n;
        int i = 0;
        for (i = 0; i < n; ++i) {
            if (nums[i] == val) {
                swap(nums[i], nums[n - 1]);
                r--;
                n--;
                --i;
            }
        }
        return r;
    }
};