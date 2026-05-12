class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        cache.assign(s.size() + 1, true);
        return wordBreakHelper(s, 0, wordDict);
    }
private:
    vector<bool> cache;
    bool wordBreakHelper(string& s, int start, vector<string>& wordDict) { 
        if (start == s.size()) return true;

        for (auto w : wordDict) {
            if (substrCompare(s, start, w) && cache[start + w.size()])
                if (wordBreakHelper(s, start + w.size(), wordDict))
                    return true;
        }

        cache[start] = false;
        return false;
    }

    bool substrCompare(string& s1, int start, string& s2) {
        int n = s2.size();
        if (start + n > s1.size()) return false;
    
        for (int i = 0; i < n; ++i) {
            if (s1[start + i] != s2[i])
                return false;
        }
        return true;
    }
};
