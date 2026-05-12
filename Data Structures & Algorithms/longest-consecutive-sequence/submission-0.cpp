class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int biggest = 1;

        // starting, ending
        unordered_map<int, pair<int, int>> seq;

        for (int n : nums) {
            if (seq.count(n)) continue;

            int new_s = seq.count(n - 1) ? n - seq[n - 1].second : n;

            int new_e = seq.count(n + 1) ? n + seq[n + 1].first : n;

            int new_l = new_e - new_s + 1;

            seq[new_e].second = new_l;

            seq[new_s].first = new_l;

            if (new_l > biggest) biggest = new_l;
        }

        return biggest;
    }
};
