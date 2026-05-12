class Solution {
private:
    vector<vector<int>> memo;

    bool dfs(string s, int sz, int idx) {
        if (idx >= s.size()) return sz == 0;

        if (memo[sz][idx] != 2) return memo[sz][idx] == 1;

        bool res = false;
        switch (s[idx]) {
            case '(':
                res |= dfs(s, sz + 1, idx + 1);
                break;
            case ')':
                if (sz <= 0) return memo[sz][idx] = 0;
                res |= dfs(s, sz - 1, idx + 1);
                break;
            case '*':
                res |= dfs(s, sz + 1, idx + 1);
                
                if (sz > 0) res |= dfs(s, sz - 1, idx + 1);
                
                res |= dfs(s, sz, idx + 1);
        }

        return memo[sz][idx] = (int)res;
    }

public:
    bool checkValidString(string s) {
        memo.assign(s.size(), vector<int>(s.size(), 2)); // 0 = false, 1 = true, 2 = idk
        return dfs(s, 0, 0);
    }
};
