class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = (r - l + 1) / 2;

        while (l < r && l != r) {
            if (nums[l] < nums[m]) {
                if (target >= nums[l] && target <= nums[m]) r = m;
                else l = m;
            } else if (nums[m] < nums[r]) {
                if (target >= nums[m] && target <= nums[r]) l = m;
                else r = m;
            }
            m = (r - l + 1) / 2 + l;

            if (l == m || r == m) break;
        }
        if (nums[l] == target) return l;
        else if (nums[r] == target) return r;
        else return -1;
    }
};
