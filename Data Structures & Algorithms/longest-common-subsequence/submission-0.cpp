class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));

        return dfs(text1, text2, 0, 0);
    }
private:
    vector<vector<int>> memo;

    int dfs(string& s1, string& s2, int idx1, int idx2) {
        if (idx1 >= s1.size() || idx2 >= s2.size()) return 0;
    
        if (memo[idx1][idx2] != -1) return memo[idx1][idx2];

        int advanceBoth = 0, ignore1 = 0, ignore2 = 0;
        if (s1[idx1] == s2[idx2])
            advanceBoth = 1 + dfs(s1, s2, idx1 + 1, idx2 + 1);
        else {
            ignore1 = dfs(s1, s2, idx1 + 1, idx2);
            ignore2 = dfs(s1, s2, idx1, idx2 + 1);
        }

        memo[idx1][idx2] = max({advanceBoth, ignore1, ignore2});
        return memo[idx1][idx2];
    }
};
