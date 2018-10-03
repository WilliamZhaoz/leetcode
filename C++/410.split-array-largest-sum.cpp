// version 1 : binary search to find the min(max(subarray))
// 1. start = max(nums) s.t. m = nums.size(), end = sum(nums) s.t. m = 1
// 2. query the number(k) of sub-array which <= mid, if k > m -> mid(result) can be bigger
// 3. in a word, find the last number the nums can be splited into m, when every sub-array is smaller than result.        
/*
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long start = 0, end = 0; // start: max(nums), end: sum(nums)
        for (int i = 0; i < nums.size(); i++) {
            start = max(start, (long long)nums[i]);
            end += nums[i];
        }
        while (start + 1 < end) {
            long long mid = start + (end - start) / 2;
            if (helper(nums, m, mid)) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (helper(nums, m, end)) {
            return end;
        }
        return start;
    }
    bool helper(vector<int> nums, int m, long long sum) {
        int c = 0, tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp += nums[i];
            if (tmp >= sum) {
                c++;
                tmp = nums[i];
            }
            if (c >= m) {
                return true;
            }
        }
        return false;
        
    }
};
*/
// version 2: dp
// dp[i][j] : the first j numbers in nums, m = i
// dp[i][j] = min(dp[i][j], max(dp[i - 1][jj], sum(from jj to end))  s.t. 1 <= jj <= nums.size())
// return dp[m][nums.size()]

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> sum(nums.size() + 1, 0);
        int cursum = 0;
        vector<vector<int>> dp(m + 1, vector<int>(nums.size() + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= nums.size(); j++) {
                for (int k = i - 1; k < j; k++) {
                    int tmp = max(dp[i - 1][k], sum[j] - sum[k]);
                    dp[i][j] = min(tmp, dp[i][j]);
                } 
                
            }
        }
        return dp[m][nums.size()];
    }
};
