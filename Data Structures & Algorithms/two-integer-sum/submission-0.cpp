class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, std::pair<bool, int>> check;
        for (int i = 0; i < nums.size(); ++i) {
            if (check[target - nums[i]].first){
                 return {check[target - nums[i]].second, i};
            }
            check[nums[i]] = make_pair(true, i);
        }
        return {0,1};
    }
};
