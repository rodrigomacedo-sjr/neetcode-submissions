class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n <= 0) return 0;

        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        int erasedIntervals = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prevEnd) {
                prevEnd = min(prevEnd, intervals[i][1]);
                erasedIntervals++;
            }
            else {
                prevEnd = intervals[i][1];
            }
        }

        return erasedIntervals;
    }
};
