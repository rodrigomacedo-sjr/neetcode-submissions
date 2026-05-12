class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;

        int b = 0;
        int e = s.size() - 1;

        while (b < e) {
            while (!isalnum(s[b]) && b < e) b++;
            while (!isalnum(s[e]) && b < e) e--;

            if (tolower(s[b++]) != tolower(s[e--])) return false;
        }
        return true;
    }
};
