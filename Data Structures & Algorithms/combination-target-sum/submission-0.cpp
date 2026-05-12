class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            trySum({}, 0, target, i, nums);
        }

        return ans;
    }
private:
    vector<vector<int>> ans = {};

    void trySum(vector<int> cur_try, int cur_sum, int target, int idx, vector<int>& nums) {
        int n = nums[idx];
        cur_try.push_back(n);
        cur_sum += n;

        if (cur_sum == target) ans.push_back(cur_try);
        else if (cur_sum > target) return;
        else {
            for (int i = idx; i < nums.size(); ++i) {
                trySum(cur_try, cur_sum, target, i, nums);
            }
        }
    }
};
