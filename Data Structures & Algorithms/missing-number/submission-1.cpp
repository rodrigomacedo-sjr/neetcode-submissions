class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) {
            sum += num;
        }
        return ((n*n + n) / 2) - sum;
    }
};
