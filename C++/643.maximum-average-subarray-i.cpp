class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxs = INT_MIN, curs = 0;
        for (int i = 0; i < k; i++) {
            curs += nums[i];
        }
        maxs = curs;
        for (int i = k; i < nums.size(); i++) {
            curs -= nums[i - k];
            curs += nums[i];
            maxs = max(maxs, curs);
        }
        return (double)maxs / k;
    }
};