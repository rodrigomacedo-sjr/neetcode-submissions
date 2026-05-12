class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int left, right;
        for (int i = 0; i < s.size(); ++i)
            for (int j = 0; j < 2; ++j) {
                left = i;
                right = i + j;

                while (left >= 0 && right < s.size() && s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
                }
            }
        return count;
    }
};
