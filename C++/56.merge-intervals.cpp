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
    // version 1
    /*
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            if (a.start == b.start) {
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        for (int i = 0; i < intervals.size(); i++) {
            if (i != intervals.size() - 1 && intervals[i].end >= intervals[i + 1].start) {
                intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
                intervals.erase(intervals.begin() + i + 1);
                i--;
            }
        }
        return intervals;
    }
    */
    // version 2 : scan line
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        vector<pair<int, int>> line;
        for (auto it : intervals) {
            line.push_back(pair<int, int>{it.start, 1});
            line.push_back(pair<int, int>{it.end, -1});
        }
        sort(line.begin(), line.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        int c = 0, start = line[0].first, end = line[0].second;
        vector<Interval> res;
        for (int i = 0; i < line.size(); i++) {
            if (c == 0) {
                start = line[i].first;
            }
            c += line[i].second;
            end = line[i].first;
            if (i != 0 && c == 0) {
                res.push_back(Interval(start, end));
            }
        }
        return res;
    }

};