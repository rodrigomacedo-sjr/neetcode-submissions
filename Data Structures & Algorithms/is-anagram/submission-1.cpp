class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char,int> alphabet1;
        std::map<char,int> alphabet2;

        for (auto c : s) {
            alphabet1[c]++;
        }

        for (auto c :  t) {
            alphabet2[c]++;
        }

if (s.size() > t.size()) {


        for (auto &p : alphabet1) {
            if (alphabet2[p.first] != p.second) return false;
        }
} else {
    for (auto &p : alphabet2) {
        if (alphabet1[p.first] != p.second) return false;
    }
}

        return true;
    }
};
