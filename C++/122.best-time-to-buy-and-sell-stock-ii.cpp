class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // version 1: 
        /*
        int res = 0; 
        for (int i = 1; i < prices.size(); i++) {
            res += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
        }
        return res;
        */
        // version 2: buy: buy state, sell: sell state
        if (prices.empty()) {
            return 0;
        }
        int buy = -prices[0], sell = 0;
        for (int i = 0; i < prices.size(); i++) {
            buy = max(sell - prices[i], buy);
            sell = max(buy + prices[i], sell);
        }
        return sell;

    }
};