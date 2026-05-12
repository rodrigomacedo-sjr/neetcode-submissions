class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();

        vector<int> ans(sz);
        ans[0] = 1;
        for (int i = 1; i < sz; ++i) {
            ans[i] = ans[i - 1] * nums[i -  1];
        }

        int postfixProduct = 1;
        for (int i = sz - 1; i >= 0; --i) {
            ans[i] *= postfixProduct;
            postfixProduct *= nums[i];
        }

        return ans;
    }
};
