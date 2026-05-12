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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        int max_conflicts = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto interval : intervals) {
            while (!pq.empty() && interval.start >= pq.top()) {
                pq.pop();
            }

            pq.push(interval.end);
            
            max_conflicts = max((int)pq.size(), max_conflicts);
        }

        return max_conflicts;
    }
};
