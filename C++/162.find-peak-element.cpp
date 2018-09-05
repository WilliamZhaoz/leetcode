class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if ((start == 0 || nums[start] > nums[start - 1]) && nums[start] > nums[start + 1]) {
            return start;
        }
        if ((end == nums.size() - 1 || nums[end] > nums[end + 1]) && nums[end] > nums[end - 1]) {
            return end;
        }
    }
};