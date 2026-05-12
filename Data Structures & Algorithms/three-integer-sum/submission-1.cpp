class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum, l, r, target;

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; ++i) {
          if (i > 0 && nums[i] == nums[i - 1]) continue;
          if (nums[i] > 0) break;

          l = i + 1;
          r = nums.size() - 1;
          target = -nums[i];
          while (l < r) {
            sum = nums[l] + nums[r];
            if (sum > target) { r--; continue; }
            if (sum < target) { l++; continue; }
            if (sum == target) {
              ans.push_back({nums[l], nums[r], nums[i]});
              l++;
              r--;
              while (l < r && nums[l] == nums[l - 1]) l++;
              while (l < r && nums[r] == nums[r + 1]) r--;
            }
          }
        }
        return ans;
    }
};
