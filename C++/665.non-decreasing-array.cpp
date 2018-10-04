class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool tag = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (tag) {
                    return false;
                }
                tag = true;
                if ((i > 0 && nums[i - 1] > nums[i + 1]) && (i + 2 < nums.size() && nums[i] > nums[i + 2])) {
                    return false;
                }
            }
        }
        return true;
    }
};