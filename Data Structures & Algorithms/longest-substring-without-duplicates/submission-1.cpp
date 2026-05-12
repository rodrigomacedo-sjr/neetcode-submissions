class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, max_size = 0;
        unordered_map<char, int> seen;

        while (r < s.size()) {
          if (seen[s[r]]) {
            while (s[l] != s[r]) {
              seen[s[l]] = false;
              l++;
            }
            l++;
          } else {
            seen[s[r]] = true;
            max_size = max(r - l + 1, max_size);
          }
          r++;
        }

        return max_size;
    }
};
