class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // start = -1, end = -2 for case [1, 2, 3, 4], the start and end have no update
        // find cur max from left, if cur value = max, then cur value is max and the array is ascending
        // else if cur value < max, it need to move before, so it is the end to sort currently.
        int start = -1 , end = -2 , mx = INT_MIN, mn = INT_MAX, l = nums.size();
        for (int i = 0; i < l; i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[l - i - 1]);
            if (mx > nums[i]) {
                end = i;
            }
            if (mn < nums[l - i - 1]) {
                start = l - i - 1;
            }
        }
        return end - start + 1;
        // version 2: sort and compare
    }
};