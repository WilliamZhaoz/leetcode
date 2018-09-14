class Solution {
public:
    // find the element smaller than nums[0], if not found, the nums is in order, return nums[0]
    /*
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return INT_MAX;
        }
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[0]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        // cout<<start<<end;
        if (nums[start] < nums[0]) {
            return nums[start];
        }
        if (nums[end] < nums[0]) {
            return nums[end];
        }
        return nums[0];
    }
    */
    // version 2: directly binary search, find the element after the breakpoint(the smaller one)
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (nums[start] < nums[end]) {
            return nums[start];
        }
        return nums[end];
    }
};
