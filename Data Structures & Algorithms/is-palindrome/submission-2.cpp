class Solution {
public:
  bool isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;

    while (start < end) {
      if (!isalpha(s[start]) && !isdigit(s[start])) {
        start++;
        continue;
      }
      if (!isalpha(s[end]) && !isdigit(s[end])) {
        end--;
        continue;
      }

      if (tolower(s[start++]) != tolower(s[end--]))
        return false;
    }
    return true;
  }
};