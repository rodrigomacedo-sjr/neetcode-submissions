class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp1 = 1;
        int dp2 = 0;

        for (int i = n - 1; i >= 0; --i) {
            int curr = 0;
            if (s[i] != '0')
                curr += dp1;

            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                curr += dp2;

            dp2 = dp1;
            dp1 = curr;
        }

        return dp1;
    }
};
