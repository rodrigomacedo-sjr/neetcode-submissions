class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for (auto n : nums) {
            for (auto v : ans) {
                v.push_back(n);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
