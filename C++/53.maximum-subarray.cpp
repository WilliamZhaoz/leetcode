class Solution {
public:
    // version 1: dp
    // dp[i] : the max subarray ending with nums[i]
    // dp[i] = max(dp[i - 1], nums[i])
    // return max(dp)
    /*
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, cur = 0;
        for (auto n : nums) {
            cur = max(cur + n, n);
            res = max(cur, res);
        }
        return res;
    }
    */
    // version 2: devide & conquer
    // divide the problem into left half, right, and mid max subarray
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int> &nums, int start, int end) {
        if (start >= end) {
            return nums[start];
        }
        int mid = start + (end - start) / 2;
        int mmax = INT_MIN, mmaxt = 0; 
        for (int i = mid; i >= start; i--) {
            mmaxt += nums[i];
            mmax = max(mmax, mmaxt);
        }
        mmaxt = mmax;
        for (int i = mid + 1; i <= end; i++) {
            mmaxt += nums[i];
            mmax = max(mmax, mmaxt);
        }
        return max(mmax, max(helper(nums, start, mid - 1), helper(nums, mid + 1, end)));
    }
};