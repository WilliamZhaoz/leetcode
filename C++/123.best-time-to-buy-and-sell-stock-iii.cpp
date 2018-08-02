class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        // version 1: state sell1 sell2 buy1 buy 2(buy[n], sell[n], n = 2) like No.122 O(n)
        /*
        if (prices.size() <= 1) {
            return 0;
        }
        int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
        */
        // version 2: break the prices into 2 part, find the best break point O(n2) 
        // TLE
        /*
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            int curmin = INT_MAX, pro1 = 0, pro2 = 0;
            for (int j = 0; j <= i; j++) {
                curmin = min(curmin, prices[j]);
                pro1 = max(pro1, prices[j] - curmin);
            }
            curmin = INT_MAX;
            for (int j = i; j < prices.size(); j++) {
                curmin = min(curmin, prices[j]);
                pro2 = max(pro2, prices[j] - curmin);
            }
            res = max(pro1 + pro2, res);          
        }
        return res;
        */
        // version 3: global state and local state
        // global[k][i] : k, the kth transactions. i, first i days
        // local[k][i] : is same with global state, but sell at the ith days
        // global[k][i] = max(local[k][i], global[k][i - 1])
        // local[k][i] = max(global[k - 1][i - 1], local[k][i - 1]) + prices[i] - prices[i - 1]
        if (prices.size() < 2) {
            return 0;
        }
        vector<int> global(3, 0);
        vector<int> local(3, 0);
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            for (int k = 2; k >= 1; k--) {
                local[k] = max(global[k - 1], local[k]) + diff;
                global[k] = max(global[k], local[k]);
            }
        }
        return global[2];
    }
};