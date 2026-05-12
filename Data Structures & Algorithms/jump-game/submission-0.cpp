class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] >= dist)
                dist = 0;
            dist++;
        }
        return dist == 1;
    }
};
