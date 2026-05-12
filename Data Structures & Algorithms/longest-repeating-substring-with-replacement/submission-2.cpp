class Solution {
public:
  int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    int maxFreq = 0;
    int l = 0, r = 0;
    int best = 0;

    while (r < s.size()) {
      freq[s[r] - 'A']++;
      maxFreq = max(freq[s[r] - 'A'], maxFreq);

      while (r - l + 1 - maxFreq > k) {
        freq[s[l] - 'A']--;
        l++;
      }
      best = max(best, r - l + 1);
      r++;
    }
    return best;
  }
};