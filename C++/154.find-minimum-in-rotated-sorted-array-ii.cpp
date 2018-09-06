class Solution {
public:
    int findMin(vector<int>& nums) {
        // version 1 : simply one for loop
        /*
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            res = min(res, nums[i]);
        }
        return res;
        */
        // version 2 : binary search, but the worest time complexity is O(n) still, e.g. 1111011111
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[start] == nums[end]) {
                start++;
            } else if (nums[mid] <= nums[end]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return min(nums[start], nums[end]);
        
    }
};