/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int len = intervals.size();

        if (len <= 1) return true;

        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });

        for (int i = 1; i < len; ++i) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }

        return true;
    }
};
