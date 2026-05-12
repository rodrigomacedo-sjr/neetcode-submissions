class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, max_size = 0, cur_size = 0;
        unordered_map<char, bool> seen;

        while (r < s.size()) {
          if (seen[s[r]]) {
            while (s[l] != s[r]) {
              seen[s[l]] = false;
              l++;
              cur_size--;
            }
            l++;
          } else {
            seen[s[r]] = true;
            cur_size++;
            max_size = max(cur_size, max_size);
          }
          r++;
        }

        return max_size;
    }
};
