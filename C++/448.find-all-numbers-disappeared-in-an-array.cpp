class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // version 1: put the number on his right position.
        /*
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
        */
        // version 2: use sign to record the attendant
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};