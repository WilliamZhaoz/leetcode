/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto interval : intervals) {
            m[interval.start]++;
            m[interval.end]--;
        }
        int res = 0, cur = 0;
        for (auto e : m) {
            cur += e.second;
            res = max(res, cur);
        }
        return res;      
    }
};