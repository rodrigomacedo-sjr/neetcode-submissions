class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() == 0) return "#";

        string ans;
        string ans2;
        for (auto &s : strs) {
            ans += to_string(s.size());
            ans += ',';
            ans2 += s;
        }
        ans[ans.size() - 1] = '#';
        return ans + ans2;
    }

    vector<string> decode(string s) {
        if (s == "#") return {};

        string cur_num;
        vector<int> sizes;
        int start;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',') {
                sizes.push_back(stoi(cur_num));
                cur_num = "";
            } else if (s[i] == '#') {
                sizes.push_back(stoi(cur_num));
                start = ++i;
                break;
            } else {
                cur_num += s[i];
            }
        }

        vector<string> ans;

        for (auto sz : sizes) {
            ans.push_back(s.substr(start, sz));
            start += sz;
        }

        return ans;
    }
};
