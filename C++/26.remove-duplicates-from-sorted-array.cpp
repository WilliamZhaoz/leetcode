class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int i = 1, j = 1;
        while (i < nums.size()) {
            if (nums[i] != nums[i - 1]) {
                nums[j++] = nums[i];
            }
            i++;
        }
        return j;
    }
};