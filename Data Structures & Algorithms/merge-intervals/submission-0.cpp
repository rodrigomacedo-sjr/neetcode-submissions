class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),  [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> ans;
        int myGuy = 0;
        bool inserted = false;
        for (int i = 0; i < n; ++i) {
            if (intervals[i][0] < intervals[myGuy][0] && intervals[i][1] < intervals[myGuy][0]) {
                ans.push_back(intervals[i]);
            }

            if (intervals[i][0] <= intervals[myGuy][1] && intervals[i][1] >= intervals[myGuy][0]) {
                intervals[myGuy][0] = min(intervals[myGuy][0], intervals[i][0]);
                intervals[myGuy][1] = max(intervals[myGuy][1], intervals[i][1]);
            }

            if (intervals[i][0] > intervals[myGuy][1]) {
                ans.push_back(intervals[myGuy]);
                myGuy = i;
            }
        }
        ans.push_back(intervals[myGuy]);
        return ans;
    }
};
