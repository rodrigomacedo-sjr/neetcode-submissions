class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) {
            counts[n]++;
        }

        priority_queue<pair<int, int>> topK;
        for (auto p : counts) {
            topK.push(make_pair(p.second, p.first));
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(topK.top().second);
            topK.pop();
        }
        return result;
    }
};
