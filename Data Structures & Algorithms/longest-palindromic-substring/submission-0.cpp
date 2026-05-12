class Solution {
public:
    string longestPalindrome(string s) {
        int max_size = 1;
        int max_l = 0, max_r = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < 2; ++j) {
                if (i + j >= s.size()) continue;

                int cur_l = i, cur_r = i + j;

                while (cur_l >= 0 && cur_r < s.size() && s[cur_l] == s[cur_r]) {
                    cur_l--;
                    cur_r++;
                }

                if (--cur_r - ++cur_l + 1 > max_size) {
                    max_l = cur_l;
                    max_r = cur_r;
                    max_size = cur_r - cur_l + 1;
                }
            }
        }
        return s.substr(max_l, max_r - max_l + 1);
    }
};
