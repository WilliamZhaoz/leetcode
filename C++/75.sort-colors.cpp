class Solution {
public:
    void sortColors(vector<int>& nums) {
        // version 1 : count sort
        /*
        vector<int> count(3, 0);
        for (auto color : nums) {
            count[color]++;
        }
        int start = 0;
        for (int i = 0; i < 3; i++) {
            while (count[i]) {
                count[i]--;
                nums[start++] = i;
            }
        }
        */
        // version 2 : tow points
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left++]);
            }
            if (nums[i] == 2) {
                swap(nums[i--], nums[right--]);
            }
        }
    }
};