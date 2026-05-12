class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size();

        if (sz == 1) return isValid(s, 0, 1) ? 1 : 0;

        vector<int> dp(sz, 0);

        dp[sz - 1] = isValid(s, sz - 1, 1) ? 1 : 0;

        dp[sz - 2] += isValid(s, sz - 2, 1) ? dp[sz - 1] : 0;
        dp[sz - 2] += isValid(s, sz - 2, 2) ? 1 : 0;

        for (int i = sz - 3; i >= 0; --i) {
            if (isValid(s, i, 1)) {
                dp[i] += dp[i + 1];
            }

            if (isValid(s, i, 2)) {
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
private:
    bool isValid(string& s, int start, int len) {
        if (start + len > s.size()) return false;

        string num_str = s.substr(start, len);

        if (num_str[0] == '0') return false;

        int num = stoi(num_str);

        return num >= 1 && num <= 26;
    }
};
