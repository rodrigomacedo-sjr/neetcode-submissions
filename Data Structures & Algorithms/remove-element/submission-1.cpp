class Solution {
private:
    void bubble(vector<int>& nums, int idx) {
        int n = nums.size();
        for (int i = idx; i < n - 1; ++i) {
            int temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
        }
    }

public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int r = n;
        int i = 0;
        for (i = 0; i < n; ++i) {
            if (nums[i] == val) {
                bubble(nums, i);
                r--;
                n--;
                --i;
            }
        }
        return r;
    }
};