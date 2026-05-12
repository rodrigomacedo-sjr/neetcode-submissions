class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (auto &s : strs) {
            vector<int> count(26);
            for (auto c : s) count[c - 'a']++;

            string key;
            for (auto n : count) {
                key += '#';
                key += n;
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto kv : groups) ans.push_back(kv.second);
        return ans;
    }
};
