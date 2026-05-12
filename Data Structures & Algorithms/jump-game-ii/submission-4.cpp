class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) return 0;

        vector<int> jumps(n, 0);

        for (int i = n - 2; i >= 0; --i) {
            int cur_min = INT_MAX - 1;
            for (int j = 1; j <= nums[i] && (i + j) < n; ++j) {
                cur_min = min(cur_min, jumps[i + j]);
            }
            jumps[i] = 1 + cur_min;
        }
        return jumps[0];
    }
};