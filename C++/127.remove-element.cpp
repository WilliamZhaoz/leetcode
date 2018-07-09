class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // version 1: 2 pointers
        /*
        if (nums.empty()) {
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (nums[right] == val && left < right) {
                right--;
            }
            while (nums[left] != val && left < right) {
                left++;
            }
            while (nums[left] == val && nums[right] != val && left < right) {
                swap(nums[left++], nums[right--]);
            }
        }
        return left + (nums[left] != val);
        */
        // version 2: 
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i];
        }
        return res;
    }
};