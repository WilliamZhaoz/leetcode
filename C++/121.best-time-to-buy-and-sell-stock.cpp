class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, cur_min = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            cur_min = min(cur_min, prices[i]);
            res = max(res, prices[i] - cur_min);
        }
        return res;
    }
};