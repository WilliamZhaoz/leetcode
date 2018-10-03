class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // binary search
        // for every houses find the first heaters >= house's position, and the prior is the last <= house's position, got the min(distance)
        // refresh the min(distance) is the result
        int res = 0;
        if (houses.empty()) {
            return res;
        }
        if (heaters.empty()) {
            return -1;
        }
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i++) {
            auto h = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            int diff = INT_MAX;
            if (h != heaters.end()) {
                diff = abs(*h - houses[i]);   
            } else {
                diff = abs(heaters[heaters.size() - 1] - houses[i]);
            }
            if (h != heaters.begin()) {
                diff = min(diff, abs(houses[i] - heaters[h - heaters.begin() - 1]));
            }
            res = max(res, diff);
        }
        return res;
        
    }
};