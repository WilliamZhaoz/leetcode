class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sumall = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < 4 || sumall % 4 != 0) {
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        vector<int> sum4(4, 0);
        return helper(nums, sum4, sumall / 4, 0);
        
    }
    bool helper(vector<int>& nums, vector<int> &sum4, int target, int start) {
        if (start >= nums.size()) {
            if (sum4[0] == target && sum4[1] == target && sum4[2] == target && sum4[3] == target) {
                return true; 
            }
            return false;
        }
        for (int i = 0; i < 4; i++) {
            if (sum4[i] + nums[start] > target) {
                continue;
            }
            sum4[i] += nums[start];
            if (helper(nums, sum4, target, start + 1)) {
                return true;
            }
            sum4[i] -= nums[start];
        }
        return false;
    }
};