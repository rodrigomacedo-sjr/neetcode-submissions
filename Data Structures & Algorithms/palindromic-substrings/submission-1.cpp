class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            count += countPalindromes(s, i, i);
            count += countPalindromes(s, i, i + 1);
        }
            
        return count;
    }
private:
    int countPalindromes(string& word, int left, int right) {
        int n = word.size(), count = 0;
        while(left >= 0 && right < n && word[left] == word[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};
