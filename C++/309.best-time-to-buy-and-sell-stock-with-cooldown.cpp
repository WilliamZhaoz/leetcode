class Solution {
public:
    // version 1: dp
    // buy[i], sell[i]
    // buy[i] = max(buy[i], sell[i - 2] - prices[i])
    // sell[i] = max(sell[i], buy[i - 1] + prices[i])
    // return sell[prices.size()]
    // space optimization: buy[i] -> buy, sell[i] -> sell1, sell2
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int buy = -prices[0], sell = 0, sell_cache = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy = max(buy, sell_cache - prices[i]);
            sell_cache = sell;
            sell = max(sell, buy + prices[i]);
        }
        return sell;
    }
};