class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // version 1: BS & DP
        // after sorting increasing by the w and  decreasing by the h, this problem is equle to "Longest Increasing Subsequence"
        // dp[i] means the min value of the last value of the size(dp) increasing subsequence
        // lower_bound function can implemented by Binary Search
        /*
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end()) dp.push_back(envelopes[i].second);
            else *it = envelopes[i].second;
        }
        return dp.size();
        */
        // version 2: only traditional DP
        int res = 0, n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};