class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size(), prev1 = 0, prev2 = 0, curr = 0;

        if (sz == 1) return s[0] != '0' ? 1 : 0;

        prev2 = s[sz - 1] != '0' ? 1 : 0;

        prev1 = s[sz - 2] != '0' ? prev2 : 0;
        prev1 += s[sz - 2] == '1' || (s[sz - 2] == '2' && s[sz - 1] <= '6') ? 1 : 0;

        for (int i = sz - 3; i >= 0; --i) {
            curr = 0;
            if (s[i] != '0')
                curr += prev1;

            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                curr += prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
