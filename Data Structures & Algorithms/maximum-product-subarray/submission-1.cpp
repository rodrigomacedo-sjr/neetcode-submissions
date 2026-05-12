class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0], n = nums.size();
        int curr_max = 1, curr_min = 1;

        for (int i = 0; i < n; ++i) {
            int join_max = nums[i] * curr_max;
            int join_min = nums[i] * curr_min;
            curr_max = max(join_max, max(join_min, nums[i]));
            curr_min = min(join_max, min(join_min, nums[i]));

            max_product = max(max_product, curr_max);
        }

        return max_product;
    }
};
