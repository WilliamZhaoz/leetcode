class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int start = 0, end = nums.size() - 1, mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (nums[start] >= target) {
            return start;
        } else if (nums[end] >= target) {
            return end;
        } else {
            return end + 1;
        }
        
    }
};