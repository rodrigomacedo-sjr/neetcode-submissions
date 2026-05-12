class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool done = false;
        for (auto interval: intervals) {
            if (interval[0] < newInterval[0] && interval[1] < newInterval[0]) {
                ans.push_back(interval);
                continue;
            }

            if (interval[0] <= newInterval[1] && interval[1] >= newInterval[0]) {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
                continue;
            }

            if (interval[0] > newInterval[1] && !done) {
                ans.push_back(newInterval);
                done = true;
            }

            if (interval[0] > newInterval[1]) {
                ans.push_back(interval);
            }
        }
        if (!done) ans.push_back(newInterval);
        return ans;
    }
};
