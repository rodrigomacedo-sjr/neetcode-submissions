class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[i][j] == '#') {
                    ans += "\\#";
                } else {
                    ans += strs[i][j];    
                }
            }
            ans += '#';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string current_word;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '\\' && s[i + 1] == '#') {
                current_word += '#';
                i++;
            }
            else if (s[i] == '#') {
                ans.push_back(current_word);
                current_word = "";
            }
            else {
                current_word += s[i];
            }
        }
        return ans;
    }
};
