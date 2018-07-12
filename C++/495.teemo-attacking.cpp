class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = duration;
        if (timeSeries.empty()) {
            return 0;
        }
        for (int i = 1; i < timeSeries.size(); i++) {
            res += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return res;
    }
};