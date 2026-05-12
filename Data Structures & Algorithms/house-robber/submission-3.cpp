class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int curr = 0;

        for (auto value : nums) {
            int temp = curr;
            curr = max(value + prev, curr);
            prev = temp;
        }

        return curr;
    }
};
