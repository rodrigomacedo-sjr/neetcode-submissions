class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        failed.assign(s.size() + 1, false);
        return wordBreakHelper(s, 0, wordDict);
    }
private:
    vector<bool> failed;
    bool wordBreakHelper(string& s, int start, vector<string>& wordDict) { 
        if (start == s.size()) return true;

        for (auto w : wordDict) {
            if (!failed[start + w.size()] && !s.compare(start, w.size(), w))
                if (wordBreakHelper(s, start + w.size(), wordDict))
                    return true;
        }

        failed[start] = true;
        return false;
    }
};
