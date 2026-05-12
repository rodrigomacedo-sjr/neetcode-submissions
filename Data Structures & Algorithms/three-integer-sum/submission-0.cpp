class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int s, e, t;

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; ++i) {
          if (i > 0 && nums[i] == nums[i - 1]) continue;

          s = i + 1;
          e = nums.size() - 1;
          t = -nums[i];
          while (s < e) {
            if (s > i + 1 && nums[s] == nums[s - 1]) { s++; continue; }
            if (e < nums.size() - 1 && nums[e] == nums[e + 1]) { e--; continue; }

            if (nums[s] + nums[e] > t) { e--; continue; }
            if (nums[s] + nums[e] < t) { s++; continue; }
            if (nums[s] + nums[e] == t) {
              ans.push_back({nums[s], nums[e], nums[i]});
              s++;
            }
          }
        }
        return {ans};
    }
};
