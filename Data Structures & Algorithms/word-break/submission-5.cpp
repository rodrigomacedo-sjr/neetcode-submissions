class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> memo(n + 1, false);
        memo[n] = true;
        for (int i = n; i >= 0; --i) {
            for (auto w : wordDict) {
                int len = w.size();
                if (i + len > n) continue;
                if (memo[i + w.size()] && s.compare(i, len, w) == 0)
                    memo[i] = true;
            }
        }
        return memo[0];
    }
};
