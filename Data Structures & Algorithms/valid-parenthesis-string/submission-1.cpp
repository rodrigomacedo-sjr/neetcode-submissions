class Solution {
private:
    unordered_map<int, unordered_map<int, bool> > memo;
    bool dfs(vector<char>& v, int sz, int idx) {
        if (idx >= v.size()) return sz == 0;

        char curr = v[idx];

        if (memo.contains(sz) && memo[sz].contains(idx)) return memo[sz][idx];

        bool res = false;
        switch (curr) {
            case '(':
                res |= dfs(v, sz + 1, idx + 1);
                break;
            case ')':
                if (sz <= 0) return false;
                res |= dfs(v, sz - 1, idx + 1);
                break;
            case '*':
                res |= dfs(v, sz + 1, idx + 1);
                
                if (sz > 0) {
                    res |= dfs(v, sz - 1, idx + 1);
                }
                
                res |= dfs(v, sz, idx + 1);
        }

        return memo[sz][idx] = res;
    }

public:
    bool checkValidString(string s) {
        vector<char> vec;
        for (auto c : s)
            vec.push_back(c);
        
        return dfs(vec, {}, 0);
    }
};
