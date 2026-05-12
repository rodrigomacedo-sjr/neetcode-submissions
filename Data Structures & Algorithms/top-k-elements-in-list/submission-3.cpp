class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) {
            counts[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [num, count] : counts) {
            buckets[count].push_back(num);
        }

        vector<int> result;

        for (int i = nums.size(); result.size() < k; --i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                result.push_back(buckets[i][j]);
                if (result.size() >= k) break;
            }
        }

        return result;
    }
};