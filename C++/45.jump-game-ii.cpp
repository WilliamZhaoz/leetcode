class Solution {
public:
    int jump(vector<int>& nums) {
        // version 1 greedy:
        /*
        int res = 0, cur = 0, pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            /*
            if (cur < i) {
                return INT_MAX;
            }
            */
            if (i > pre) {
                res++;
                pre = cur;
            }
            cur = max(cur, i + nums[i]);
        }
        return res;
        */
        // version 2 dp:
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] != INT_MAX && j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[nums.size() - 1];
    }
};