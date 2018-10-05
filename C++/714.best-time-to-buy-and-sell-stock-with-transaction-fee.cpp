class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }
        int buy = -prices[0], sell = 0;
        for (int i = 0; i < prices.size(); i++) {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i] - fee);
        }
        return sell;
    }
};