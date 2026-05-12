class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<int>> groups;
        for (int i = 0; i < strs.size(); ++i) {
            map<char, int> charCount;
            // charCount.clear();
            for (auto c : strs[i]) {
                charCount[c]++;
            }
            groups[charCount].push_back(i);
        }

        vector<vector<string>> results;

        for (auto &p : groups) {
            vector<string> current;
            // current.clear();
            for (auto v : p.second) {
                current.push_back(strs[v]);
            }
            results.push_back(current);
        }

        return results;
    }
};
