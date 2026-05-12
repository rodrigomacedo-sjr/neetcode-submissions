class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = INT_MIN, cur_sum = 0;
        for (auto n : nums) {
            cur_sum = max(n, n + cur_sum);
            best_sum = max(best_sum, cur_sum);
        }
        return best_sum;
    }
};
