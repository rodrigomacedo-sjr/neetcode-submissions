class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            int curr = i, count = 0;
            while (curr > 0) {
                curr &= (curr - 1);
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};
