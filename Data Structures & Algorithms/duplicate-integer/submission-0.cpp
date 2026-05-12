class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int,bool> seen;
        for (auto i : nums) {
            if (seen[i]) return true;
            else seen[i] = true;
        }
        return false;
    }
};