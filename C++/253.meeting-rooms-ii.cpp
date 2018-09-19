/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 // version 1 : map 
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

// version 2 : scan line:
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
        vector<pair<int, int>> line;
        for (auto interval : intervals) {
            line.push_back(pair<int, int>(interval.start, 1));
            line.push_back(pair<int, int>(interval.end, -1));
        }
        sort(line.begin(), line.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        int maxc = 0, curc = 0;
        for (int i = 0; i < line.size(); i++) {
            curc += line[i].second;
            maxc = max(maxc, curc);
        }
        return maxc;
            
    }
};
