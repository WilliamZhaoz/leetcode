class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        int pivot = findPivotPos(nums);
        return binarySearch(nums, 0, max(0, pivot - 1), target) || binarySearch(nums, pivot, nums.size() - 1, target);
    }
    int findPivotPos(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[start] == nums[end]) {
                start++;
            } else if (nums[mid] <= nums[nums.size() - 1]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (nums[start] < nums[nums.size() - 1]) {
            return start;
        }
        return end;
    }
    bool binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return nums[start] == target || nums[end] == target;
    } 
};