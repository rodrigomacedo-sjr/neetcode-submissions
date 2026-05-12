class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int> freq;
      for (auto c : t) {
        freq[c]++;
      }

      int l = 0, r = 0, bestl = -1, bestr = -1;
      unordered_map<char, int> test;
      while (r < s.size()) {
        test[s[r]]++;

        while (l < r && (!freq.count(s[l]) || test[s[l]] > freq[s[l]])) {
          test[s[l]]--;
          l++;
        }

        bool valid = true;
        for (auto kv : freq) {
          if (!(kv.second <= test[kv.first])) { valid = false; break; }
        }
        if (valid) {
          if (bestl == -1 || r - l + 1 < bestr - bestl + 1) {
            bestl = l;
            bestr = r;
          }
        }
        r++;
      }
      if (bestl == -1 || bestr == -1) return "";

      return s.substr(bestl, bestr - bestl + 1);
    }
};
