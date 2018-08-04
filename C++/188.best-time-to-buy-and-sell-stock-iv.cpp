class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // version 1: dp
        // buy[i][k], the max profit at the ith day when is buy in state after kth transactions, the max profit at the ith day when is sell out states after kth transactions
        // buy[i][k] = max(buy[i - 1][k], sell[i - 1][k - 1] - prices[i])
        // sell[i][k] = max(sell[i - 1][k], buy[i - 1][k - 1] + preices[i])
        // space optimization: sell[i][k] -> sell[k]
        // return sell[k]
        /*
        if (k > prices.size() / 2) {
            return helper(prices);
        }
        vector<int> buys(k + 1, INT_MIN);
        vector<int> sells(k + 1, 0);
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                buys[j] = max(buys[j], sells[j - 1] - prices[i]);
                sells[j] = max(sells[j], buys[j] + prices[i]);
            }
        }
        return sells[k];
        */
        // version 2: dp
        // global[i][k], the max profit until the ith day after kth transactions
        // local[i][k], the max profit until the ith day after kth transactions when the last transaction is sell at ith day.
        // global[i][k] = max(global[i - 1][k], local[i][k])
        // local[i][k] = max(local[i - 1][k], global[i - 1][k - 1]) + diff 
        // space optimization: global[i][k] -> global[k]
        // return global[k]
        if (k > prices.size() / 2) {
            return helper(prices);
        }
        vector<int> global(k + 1, 0);
        vector<int> local(k + 1, 0);
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; j--) {
                local[j] = max(local[j], global[j - 1] ) + diff;
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
        
    }
    int helper(vector<int> & prices) {
        int res = 0; 
        if (prices.size() <= 2) {
            return res;
        }
        for (int i = 1; i < prices.size(); i++) {
            res += prices[i] > prices[i - 1] ? (prices[i] - prices[i - 1]) : 0;
        }
        return res;
    }
};