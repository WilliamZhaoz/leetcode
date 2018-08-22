class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int pivot = findPivot(nums);
        int left = findElement(nums, 0, pivot - 1, target);
        int right = findElement(nums, pivot, nums.size() -1, target);
        return left >= 0 ? left : right >= 0 ? right : -1;
    }
    int findPivot(vector<int> &nums) {
        int start = 0, end = nums.size() - 1, mid;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[0]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return nums[start] < nums[0] ? start : nums[end] < nums[0] ? end : 0;
    }
    int findElement(vector<int> &nums, int start, int end, int target) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return nums[start] == target ? start : nums[end] == target ? end : -1;
    }
};