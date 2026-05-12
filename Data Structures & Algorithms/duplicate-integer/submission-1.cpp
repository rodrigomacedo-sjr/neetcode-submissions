class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> seen;
        for (auto n : nums) {
            if (seen[n]) return true;
            else seen[n] = true;
        }
        return false;
    }
};