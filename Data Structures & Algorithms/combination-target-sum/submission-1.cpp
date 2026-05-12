class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> cur_try;
        trySum(cur_try, 0, target, 0, nums);

        return ans;
    }
private:
    vector<vector<int>> ans = {};

    void trySum(vector<int>& cur_try, int cur_sum, int target, int idx, vector<int>& nums) {
        if (cur_sum == target) {
            ans.push_back(cur_try);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if (cur_sum + nums[i] > target) break;

            cur_try.push_back(nums[i]);

            trySum(cur_try, cur_sum + nums[i], target, i, nums);

            cur_try.pop_back();
        }
    }
};
