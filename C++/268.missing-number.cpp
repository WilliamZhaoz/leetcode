class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i && nums[i] < nums.size()) {
                swap(nums[i], nums[nums[i]]);
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums.size();;
    }
};
