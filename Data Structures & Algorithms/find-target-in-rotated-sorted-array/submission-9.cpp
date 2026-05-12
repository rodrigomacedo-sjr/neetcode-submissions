class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = (r - l + 1) / 2;

        while (l != r) {
            if (target >= nums[l] && target <= nums[m]) r = m;
            else if (target >= nums[m] && target <= nums[r]) l = m;
            else if (
                (target >= nums[l] && target >= nums[m] && target >= nums[r]) ||
                (target <= nums[l] && target <= nums[m] && target <= nums[r])
            )
                if (nums[m] >= nums[l] && nums[m] >= nums[r])
                    l = m;
                else if (nums[l] >= nums[m] && nums[l] >= nums[r])
                    r = m;
                else return -1;
            else if (target > nums[r] && target < nums[l]) return -1;
            
            m = (r - l + 1) / 2 + l;

            if (l == m || r == m) {
                if (nums[l] == target) return l;
                if (nums[r] == target) return r;
                else return -1;
            }
        }
        return (nums[l] == target) ? l : - 1;
    }
};
