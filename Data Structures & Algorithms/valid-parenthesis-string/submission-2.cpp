class Solution {
private:
    unordered_map<int, unordered_map<int, bool> > memo;
    bool dfs(string s, int sz, int idx) {
        if (idx >= s.size()) return sz == 0;

        char curr = s[idx];

        if (memo.contains(sz) && memo[sz].contains(idx)) return memo[sz][idx];

        bool res = false;
        switch (curr) {
            case '(':
                res |= dfs(s, sz + 1, idx + 1);
                break;
            case ')':
                if (sz <= 0) return false;
                res |= dfs(s, sz - 1, idx + 1);
                break;
            case '*':
                res |= dfs(s, sz + 1, idx + 1);
                
                if (sz > 0) {
                    res |= dfs(s, sz - 1, idx + 1);
                }
                
                res |= dfs(s, sz, idx + 1);
        }

        return memo[sz][idx] = res;
    }

public:
    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }
};
