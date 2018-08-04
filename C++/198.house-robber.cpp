class Solution {
public:
    int rob(vector<int>& nums) {
        // version 1: dp[i]
        // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        // return dp[nums.size()]
        // space optimization: dp1, dp2
        /*
        int dp1 = 0, dp2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = dp2;
            dp2 = max(dp1 + nums[i], dp2);
            dp1 = tmp;
        }
        return dp2;
        */
        // version 2: rob[i], cold[i]
        // rob[i] = cold[i - 1] + nums[i]
        // cold[i] = max(cold[i - 1], rob[i - 1])
        // return max(cold[nums.szie() - 1], rob[nums.size() - 1])
        // space optimization: rob, cold
        int rob = 0, cold = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = rob;
            rob = cold + nums[i];
            cold = max(cold, tmp);
        }
        return max(cold, rob);
    }
};