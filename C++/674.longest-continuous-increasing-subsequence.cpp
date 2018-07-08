class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1] || i == 0) {
                res = max(res, ++tmp);
            } else {
                tmp = 1;
            }
        }
        return res;
    }
};