class Solution {
public:
    // version 1: dp[i], jump to the ith stairs
    /*
    int minCostClimbingStairs(vector<int>& cost) {
        int dp1 = 0, dp2 = 0, tmp;
        for (int i = 2; i <= cost.size(); i++) {
            tmp = min(dp1 + cost[i - 2], dp2 + cost[i - 1]);
            dp1 = dp2; dp2 = tmp;
        }
        return dp2;
    }
    */
    // version 2: dp[i], jump from the ith stairs
    int minCostClimbingStairs(vector<int>& cost) {
        int dp1 = cost[0], dp2 = cost[1], tmp;
        for (int i = 2; i < cost.size(); i++) {
            tmp = min(dp1, dp2) + cost[i];
            dp1 = dp2; dp2 = tmp;
        }
        return min(dp2, dp1);
    }
};