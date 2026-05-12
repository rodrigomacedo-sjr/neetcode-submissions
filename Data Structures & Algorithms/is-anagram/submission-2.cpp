class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count_s;
        for (auto c : s) {
            count_s[c]++;
        }

        unordered_map<char, int> count_t;
        for (auto c : t) {
            count_t[c]++;
        }
        return count_s == count_t;
    }
};
