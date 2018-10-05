class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0, samec = 1;
        sort(ages.begin(), ages.end());
        for (int i = 0; i < ages.size(); i++) {
            if (i + 1 < ages.size() && ages[i] == ages[i + 1]) {
                samec++;
                continue;
            }
            double left = ages[i] * 0.5 + 7;
            auto it = upper_bound(ages.begin(), ages.begin() + i, left);
            
            res += samec * (i - (it - ages.begin()));
            samec = 1;
        }
        return res;
    }
};