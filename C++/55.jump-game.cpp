class Solution {
public:
    bool canJump(vector<int>& nums) {
        // version 1 : greddy
        /*
        int curLongest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (curLongest < i) {
                return false;
            }
            curLongest = max(curLongest, nums[i] + i);
        }
        return curLongest >= nums.size() - 1;
        */
        // version 2 : dp
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size() - 1];
    }
};